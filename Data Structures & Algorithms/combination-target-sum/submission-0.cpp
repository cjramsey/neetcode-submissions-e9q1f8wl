#include <numeric>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(res, comb, nums, 0, target);
        return res;
    }

    void backtrack(vector<vector<int>>& res, 
                   vector<int>& comb, 
                   vector<int>& nums, 
                   int index,
                   int target) {
        if (index >= nums.size() || accumulate(comb.begin(), comb.end(), 0) > target) {
            return;
        }
        if (accumulate(comb.begin(), comb.end(), 0) == target) {
            res.push_back(comb);
            return;
        }
        comb.push_back(nums[index]);
        backtrack(res, comb, nums, index, target);
        comb.pop_back();
        backtrack(res, comb, nums, index + 1, target);
    }
};
