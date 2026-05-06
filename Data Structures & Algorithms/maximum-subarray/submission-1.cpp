class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int cur = 0;
        for (int n: nums) {
            cur += n;
            if (cur < 0) {
                cur = 0;
                if (n > res) {
                    res = n;
                }
            }
            else if (cur > res) {
                res = cur;
            }
        }
        return res;
    }
};
