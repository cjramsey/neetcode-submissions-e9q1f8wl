class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size(), 0);
        vector<int> right(heights.size(), 0);

        // finding right boundaries
        stack<int> mono_r;
        for (int i = 0; i < heights.size(); ++i) {
            while (!mono_r.empty() && heights[mono_r.top()] > heights[i]) {
                int idx = mono_r.top();
                mono_r.pop();
                right[idx] = i - idx - 1;
            }
            mono_r.push(i);
        }
        while (!mono_r.empty()) {
            right[mono_r.top()] = heights.size() - mono_r.top() - 1;
            mono_r.pop();
        }

        // finding left boundaries
        stack<int> mono_l;
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!mono_l.empty() && heights[mono_l.top()] > heights[i]) {
                int idx = mono_l.top();
                mono_l.pop();
                left[idx] = idx - i - 1;
            }
            mono_l.push(i);
        }
        while (!mono_l.empty()) {
            left[mono_l.top()] = mono_l.top();
            mono_l.pop();
        }
        for (const auto& n: left) {
            cout << n;
        }
        cout << '\n';
        for (const auto& n: right) {
            cout << n;
        }


        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res = max(res, heights[i] * (left[i] + right[i] + 1));
        }
        return res;
    }
};
