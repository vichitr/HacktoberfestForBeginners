class Solution {
    public int hammingDistance(int x, int y) {
     int count =0;
     String newX=String.format("%32s", Integer.toBinaryString(x)).replaceAll(" ", "0");
     String newY = String.format("%32s", Integer.toBinaryString(y)).replaceAll(" ", "0");
  
     for (int i=0;i<newX.length();i++)
         {
            if(newX.charAt(i) != newY.charAt(i))
            {
                count++;
              
            }
         }
   
   return count;
 }
}
