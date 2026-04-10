class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, {}, 0, nums);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int> cur, int i, vector<int>& nums) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }

        backtrack(res, cur, i + 1, nums);
        cur.push_back(nums[i]);
        backtrack(res, cur, i + 1, nums);
    }
};
