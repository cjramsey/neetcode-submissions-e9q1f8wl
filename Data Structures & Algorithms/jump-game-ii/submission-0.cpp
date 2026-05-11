class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int l = 0, r = 0;
        while (r < nums.size() - 1) {
            int farthest = r;
            while (l <= r) {
                farthest = max(farthest, l + nums[l]);
                ++l;
            }
            l = r + 1;
            r = farthest;
            ++steps;
        }
        return steps;
    }
};
