class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 == 1) {
            return false;
        }
        target /= 2;
        return dfs(0, nums, 0, target);
    }

    bool dfs(int sum, vector<int>& nums, int index, int target) {
        if (sum == target) {
            return true;
        }
        if (index == nums.size() || sum > target) {
            return false;
        }
        if (dfs(sum + nums[index], nums, index + 1, target)
            || dfs(sum, nums, index + 1, target)) {
                return true;
        }
        return false;
    }
};
