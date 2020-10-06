// https://leetcode.com/problems/maximum-product-subarray/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0], min_prod = nums[0], max_prod = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                int temp = min_prod;
                min_prod = max_prod;
                max_prod= temp;
            }
            max_prod = max(max_prod*nums[i], nums[i]);
            min_prod= min(min_prod*nums[i], nums[i]);
            prod= max(prod, max_prod);
        }
        return prod;
    }
};