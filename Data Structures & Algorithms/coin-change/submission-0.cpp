class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        unordered_map<int, int> dp;
        dp[0] = 0;
        return dfs(coins, amount, dp);
    }

private:
    int dfs(vector<int>& coins, int amount, unordered_map<int, int>& dp) {
        if (dp.contains(amount)) {
            return dp[amount];
        }

        int res = numeric_limits<int>::max();
        for (int n: coins) {
            if (n <= amount) {
                int cur = dfs(coins, amount - n, dp);
                if (cur == -1) {
                    continue;
                }
                res = min(res, 1 + cur);
            }
            else {
                break;
            }
        }
        if (res == numeric_limits<int>::max()) {
            res = -1;
        }
        dp[amount] = res;
        return res;
    }
};
