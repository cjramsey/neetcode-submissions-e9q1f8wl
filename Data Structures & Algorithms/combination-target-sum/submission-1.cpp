#include <numeric>

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtrack({}, nums, 0, 0, target);
        return res;
    }

    void backtrack(vector<int> comb, vector<int>& nums, int i,
                   int total, int target) {
        if (total == target) {
            res.push_back(comb);
            return;
        }
        
        for (int j = i; j < nums.size(); ++j) {
            if (total + nums[j] > target) {
                return;
            }
            comb.push_back(nums[j]);
            backtrack(comb, nums, j, total + nums[j], target);
            comb.pop_back();
        }
    }
};
