class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int n: nums) {
            if (dp[dp.size() - 1] < n) {
                dp.push_back(n);
            }
            else {
                int l = 0, r = dp.size() - 1;
                while (l < r) {
                    int m = l + (r - l) / 2;
                    if (dp[m] >= n) {
                        r = m;
                    }
                    else {
                        l = m + 1;
                    }
                }
                dp[r] = n;
            }
        }
        return dp.size();
    }
};
