class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        vector<double> arrivals(n, 0);
        for (int i = 0; i < n; ++i) {
            arrivals[i] = (target - position[i]) / static_cast<double>(speed[i]);
        }
        
        sort(indices.begin(), indices.end(), [&position](int a, int b) {
            return position[a] < position[b];
        });

        stack<int> st{};
        for (int i: indices) {
            while (!st.empty() && arrivals[st.top()] <= arrivals[i]) {
                st.pop();
            }
            st.push(i);
        }

        return st.size();
    }
};
