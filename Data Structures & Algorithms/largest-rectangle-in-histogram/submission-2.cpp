class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, n);

        stack<int> st{};
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        st = {};
        vector<int> pse(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = max(res, heights[i] * (nse[i] - pse[i] - 1));
        }

        return res;
    }
};
