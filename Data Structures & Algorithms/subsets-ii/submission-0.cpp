class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, {}, 0, true);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int> subset, int i, bool unseen) {
        if (unseen) {
            res.push_back(subset);
        }

        if (i >= nums.size()) {
            return;
        }

        subset.push_back(nums[i]);
        ++i;
        backtrack(nums, subset, i, true);
        subset.pop_back();
        while (i < nums.size() && nums[i] == nums[i - 1]) {
            ++i;
        }
        backtrack(nums, subset, i, false);
    }
};
