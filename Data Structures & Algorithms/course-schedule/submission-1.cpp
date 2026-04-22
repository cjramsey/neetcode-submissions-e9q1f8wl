class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& v: prerequisites) {
            adj[v[0]].push_back(v[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            vector<int> seen(numCourses, 0);
            if (!dfs(adj, i, seen)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adj, int crs, vector<int>& seen) {
        if (seen[crs]) {
            return false;
        }

        seen[crs] = 1;

        for (const auto& pre: adj[crs]) {
            if (!dfs(adj, pre, seen)) {
                return false;
            }
        }

        seen[crs] = 0;
        return true;
    }
};
