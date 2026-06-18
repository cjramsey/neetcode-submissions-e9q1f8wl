class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);

        stack<int> mono{};
        for (int i = 0; i < n; ++i) {
            while (!mono.empty() && temperatures[mono.top()] < temperatures[i]) {
                res[mono.top()] = i - mono.top();
                mono.pop();
            }
            mono.push(i);
        }

        return res;
    }
};
