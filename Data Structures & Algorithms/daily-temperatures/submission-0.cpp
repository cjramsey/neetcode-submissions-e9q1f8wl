#include <stack>
#include <vector>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> mono;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!mono.empty() && mono.top().first < temperatures[i]) {
                int idx = mono.top().second;
                mono.pop();
                res[idx] = i - idx;
            }
            mono.push({temperatures[i], i});
        }

        return res;
    }
};
