/* Problem 34. Find First and Last Position of Element in Sorted Array
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 */

public class First_and_last_sorted_array {
    public int[] searchRange(int[] nums, int target) {
        int[] targetRange = {-1, -1};

        for(int i = 0; i<nums.length; i++){
            if(nums[i] == target){
                targetRange[0] = i;
                break;
            }
        }

        if(targetRange[0] == -1){
            return targetRange;
        }

        for(int i = nums.length-1; i>=0; i--){
            if(nums[i] == target){
                targetRange[1] = i;
                break;
            }
        }

        return targetRange;

    }
}
