/* This code takes an array, let's say arr. If arr has 'n' distinct elements, the first n indices of arr are arranged to have thse n elements in O(n) time and with 
O(1) space (operations done in-place). The fuction returns n. So now that that arr has been arranged, the user can print or access first n elements to see elements 
without any duplicates */

class Solution {
    public int removeDuplicates(int[] nums) {
        int unique=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i+1]>nums[unique])
            {
                nums[unique+1]=nums[i+1];
                unique++;
            }
        }
        return unique+1;
    }
}
