//This program checks if an array contains any duplicate element using Set DS
class Solution {
    public boolean containsDuplicate(int[] nums) 
    {
        Set<Integer> st=new HashSet<Integer>();
        
        for(int n:nums)
        {
            if(st.add(n))
               continue;
            else
                return(true);
            
        }
        return(false);
        
    }
    public static void main()
    {
    Solution obj=new Solution();
    int arr[]={1,2,3,4,5,6,6};
    if(obj.containsDuplicate(arr) == false)
    System.out.println("contains no duplicate");
    else
    System.out.println("contains duplicate");
    }
}
