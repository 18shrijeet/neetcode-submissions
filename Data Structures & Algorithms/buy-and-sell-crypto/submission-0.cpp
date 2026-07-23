class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int leastBuy = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            profit = max(profit, prices[i]-leastBuy);
            leastBuy = min(leastBuy,prices[i]);
        }
        return profit;
    }
};
