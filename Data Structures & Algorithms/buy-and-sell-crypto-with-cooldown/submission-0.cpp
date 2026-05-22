class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // column 0 = buy
        // column 1 = sell
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, numeric_limits<int>::min()));
        return dfs(0, 0, prices, dp);
    }

    int dfs(int i, int buying, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) {
            return 0;
        }
        if (dp[i][buying] != numeric_limits<int>::min()) {
            return dp[i][buying];
        }

        if (buying == 0) {
            int buy = dfs(i + 1, 1, prices, dp) - prices[i];
            int cooldown = dfs(i + 1, 0, prices, dp);
            dp[i][buying] = max(buy, cooldown);
        }
        else {
            int sell = dfs(i + 2, 0, prices, dp) + prices[i];
            int cooldown = dfs(i + 1, 1, prices, dp);
            dp[i][buying] = max(sell, cooldown);
        }

        return dp[i][buying];
    }
};
