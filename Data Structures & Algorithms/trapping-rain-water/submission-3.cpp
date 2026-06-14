class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int area = 0;

        int l = 0;
        int r = n - 1;
        int leftMax = height[l], rightMax = height[r];

        while (l < r) {
            if (leftMax < rightMax) {
                ++l;
                leftMax = max(leftMax, height[l]);
                area += leftMax - height[l];
            }
            else {
                --r;
                rightMax = max(rightMax, height[r]);
                area += rightMax - height[r];
            }
        }

        return area;
    }
};
