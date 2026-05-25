class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexes;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (indexes.contains(target - nums[i])) {
                return {indexes[target - nums[i]], i};
            }
            indexes[nums[i]] = i;
        }
        return {};
    }
};
