class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res{};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            if (cur > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                int total = cur + nums[l] + nums[r];
                if (total == 0) {
                    res.push_back({cur, nums[l], nums[r]});
                    do {
                        ++l;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do {
                        --r;
                    } while (r > l and nums[r] == nums[r + 1]);
                }
                else if (total > 0) {
                    --r;
                }
                else {
                    ++l;
                }
            }
        }
        return res;
    }
};
