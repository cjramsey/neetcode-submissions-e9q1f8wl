class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[0];

        while (l <= r) {
            int m = l + (r - l) / 2;
            res = min(res, nums[m]);
            if (res <= nums[r]) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return res;
    }
};
