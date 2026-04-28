class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3) {
            return *max_element(nums.begin(), nums.end());
        }

        // Two copies of vector
        // One omits the first element
        // The other omits the last element
        vector<int> v(nums.begin() + 1, nums.end());

        nums[2] += nums[0];
        for (int i = 3; i < n - 1; ++i) {
            nums[i] += max(nums[i - 2], nums[i - 3]);
        }

        v[2] += v[0];
        for (int i = 3; i < n - 1; ++i) {
            v[i] += max(v[i - 2], v[i - 3]);
        }

        // Take the highest from either omit first or final value
        return max(max(nums[n - 2], nums[n - 3]), max(v[n - 2], v[n - 3]));
    }
};
