import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> numMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (numMap.containsKey(complement)) {
                return new int[]{numMap.get(complement), i};
            }
            numMap.put(nums[i], i);
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        
        Solution solution = new Solution();
        int[] result = solution.twoSum(nums, target);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
When you run this code, it will output 0 1, indicating that the elements at indices 0 and 1 (2 and 7) in the nums array add up to the target number 9.






