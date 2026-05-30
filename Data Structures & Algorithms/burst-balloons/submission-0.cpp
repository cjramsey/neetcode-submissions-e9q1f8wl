class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return dfs(1, n, nums, dp);
    }

    int dfs(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (r < l) {
            return 0;
        }
        if (dp[l][r] != -1) {
            return dp[l][r];
        } 
        int res = 0;
        for (int i = l; i <= r; ++i) {
            int cur = nums[l - 1] * nums[i] * nums[r + 1];
            int left = dfs(l, i - 1, nums, dp);
            int right = dfs(i + 1, r, nums, dp);
            res = max(res, cur + left + right);
        }
        dp[l][r] = res;
        return res;
    }
};
