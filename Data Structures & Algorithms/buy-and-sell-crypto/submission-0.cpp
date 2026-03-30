class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_seen = prices[0];
        int max_profit = 0;
        for (const auto& p: prices)
        {
            min_seen = min(min_seen, p);

            max_profit = max(max_profit, p - min_seen);
        }
        return max_profit;
    }
};
