class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res  = 0;
        int cur = 0;
        for (int n: nums) {
            if (n == 1) {
                ++cur;
                res = max(res, cur);
            }
            else {
                cur = 0;
            }
        }
        return res;
    }
};