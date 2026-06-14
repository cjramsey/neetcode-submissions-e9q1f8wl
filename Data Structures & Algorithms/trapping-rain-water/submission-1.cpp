class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st{};
        int n = height.size();
        int area = 0;
        for (int i = 0; i < n; ++i) {
            int min_h = 0; 
            while (!st.empty() && height[st.top()] <= height[i]) {
                int idx = st.top();
                area += (min(height[i], height[idx]) - min_h) * (i - idx - 1);
                min_h = height[idx];
                st.pop();
            }

            // fill in gap from prev taller bars
            if (!st.empty()) {
                int idx = st.top();
                area += (min(height[i], height[idx]) - min_h) * (i - idx - 1);
            }
            st.push(i);
        }
        
        return area;
    }
};
