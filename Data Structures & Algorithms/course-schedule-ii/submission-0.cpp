class Solution {
public:
    vector<int> res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> remaining(numCourses);
        for (const auto& p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            ++remaining[p[0]];
        }

        int finished = 0;
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (remaining[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int crs = q.front();
            q.pop();
            res.push_back(crs);
            ++finished;
            for (const auto& nei: adj[crs]) {
                --remaining[nei];
                if (remaining[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        if (finished == numCourses) {
            return res;
        }
        return {};
    }
};
