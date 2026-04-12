class Solution {
public:
    vector<vector<int>> res{};

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm{nums[0]};
        backtrack(nums, perm, 1);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int> perm, int i) {
        if (i == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (auto it = perm.begin(); it != perm.end() + 1; ++it) {
            auto add = distance(perm.begin(), it);
            it = perm.insert(it, nums[i]);
            backtrack(nums, perm, i + 1);
            perm.erase(next(perm.begin(), add));
        }
    }
};
