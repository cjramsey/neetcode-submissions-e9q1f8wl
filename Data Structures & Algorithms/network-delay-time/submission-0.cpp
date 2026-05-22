class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // ignore 0-th index for convenience
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
        for (const auto& edge: times) {
            graph[edge[0]][edge[1]] = edge[2];
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>,
            greater<tuple<int, int>>> min_heap;
        
        // ignore 0-th index for convenience
        vector<int> min_times(n + 1, numeric_limits<int>::max());
        min_times[k] = 0;
        min_times[0] = 0;

        min_heap.push({0, k});


        while (!min_heap.empty()) {
            auto cur = min_heap.top();
            min_heap.pop();
            int time = get<0>(cur);
            int node = get<1>(cur);
            for (int i = 0; i <= n; ++i) {
                int t = graph[node][i];
                if (t >= 0) {
                    if (time + t < min_times[i]) {
                        min_times[i] = time + t;
                        min_heap.push({time + t, i});
                    }
                }
            }
        }

        int res = -1;
        for (int time: min_times) {
            cout << time << ' ';
            if (time == numeric_limits<int>::max()) {
                return -1;
            }
            res = max(res, time);
        }

        return res;
    }
};
