class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        int n = strs.length;        
        
        HashMap<String, Integer> map = new HashMap<>();
        
        List<List<String>> list = new ArrayList<>();
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            char[] c = strs[i].toCharArray();
            Arrays.sort(c);
            String s = String.valueOf(c);
            
            if(map.containsKey(s)){
                int l = map.get(s);
                list.get(l).add(strs[i]);
            }else{
                List<String> w = new ArrayList<>();
                w.add(strs[i]);
                
                list.add(w);
                map.put(s, count++);
            }
        }
        return list;
        
    }
}