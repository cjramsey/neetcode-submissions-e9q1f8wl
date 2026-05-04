class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int minimum = res;
        int maximum = res;
        for (int i = 1; i < nums.size(); ++i) {
            int max_ = maximum * nums[i];
            int min_ = minimum * nums[i];
            minimum = min(min(max_, min_), nums[i]);
            maximum = max(max(max_, min_), nums[i]);
            res = max(res, maximum);
        }
        return res;
    }
};
