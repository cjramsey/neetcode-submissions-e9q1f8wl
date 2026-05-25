class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        unordered_map<int, int> dp;
        dp[0] = 0;
        return dfs(amount, coins, dp);
    }

    int dfs(int remaining, vector<int>& coins, unordered_map<int, int>& dp) {
        if (dp.contains(remaining)) {
            return dp[remaining];
        }
        
        int res = numeric_limits<int>::max();
        for (int c: coins) {
            if (c <= remaining) {
                int cur = dfs(remaining - c, coins, dp);
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
        dp[remaining] = res;
        return res;
    }
};
