class Solution {
public:
    unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(amount, coins);
        return res == numeric_limits<int>::max() ? -1 : res;
    }

    int dfs(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 0;
        }
        if (memo.contains(amount)) {
            return memo[amount];
        }

        int res = numeric_limits<int>::max();
        for (int coin: coins) {
            if (coin <= amount) {
                int result = dfs(amount - coin, coins);
                if (result != numeric_limits<int>::max()) {
                    res = min(res, 1 + result);
                }
            }
        }
        memo[amount] = res;
        return res;
    }   
};
