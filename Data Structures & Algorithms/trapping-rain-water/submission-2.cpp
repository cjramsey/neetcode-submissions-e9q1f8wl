class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st{};
        int n = height.size();
        int area = 0;
        for (int i = 0; i < n; ++i) {
            int min_h = 0; 
            while (!st.empty() && height[st.top()] <= height[i]) {
               int mid = height[st.top()];
               st.pop();
               if (!st.empty()) {
                    int right = height[i];
                    int left = height[st.top()];
                    int h = min(right, left) - mid;
                    int w = i - st.top() - 1;
                    area += h * w;
               }
            }
            st.push(i);
        }
        
        return area;
    }
};
