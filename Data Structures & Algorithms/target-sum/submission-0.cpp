class Solution {
public:
    vector<vector<int>> dp;
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), 
            vector<int>(2 * totalSum + 1, numeric_limits<int>::max()));
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + totalSum] != numeric_limits<int>::max()) {
            return dp[i][total + totalSum]; 
        }
        dp[i][total + totalSum] = dfs(i + 1, total + nums[i], nums, target) + dfs(i + 1, total - nums[i], nums, target);
        return dp[i][total + totalSum];
    }
};
