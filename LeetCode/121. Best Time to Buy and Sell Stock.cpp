// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int res = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_price){
                min_price=prices[i];
            }else if(prices[i]- min_price>res){
                res = prices[i]- min_price;
            }
        }
        return res;
    }
};