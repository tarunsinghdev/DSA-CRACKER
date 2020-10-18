class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int max_profit = 0;
        int min_ele = prices[0];
        for(int i = 0; i < prices.size(); i++){
            min_ele = min(min_ele, prices[i]);
            max_profit = max(max_profit, prices[i] - min_ele);
        }
        return max_profit;
    
    }

};
