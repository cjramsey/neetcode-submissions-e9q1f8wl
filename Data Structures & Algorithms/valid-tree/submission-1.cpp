class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj;
        vector<int> row(n);
        for (int i = 0; i < n; ++i) {
            adj.push_back(row);
        }
        for (const auto& e: edges) {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }

        for (int i = 0; i < n; ++i) {
            vector<int> cycle(n);
            if (!dfs(adj, i, cycle, n)) {
                return false;
            }
            int count = 0;
            for (const auto& node: cycle) {
                if (node == 1) {
                    ++count;
                }
                if (count == n) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<int>>& adj, int node, vector<int>& cycle, int n) {
        if (cycle[node] != 0) {
            return false;
        }

        ++cycle[node];
        for (int i = 0; i < n; ++i) {
            if (adj[node][i] == 1) {
                adj[node][i] = 0;
                adj[i][node] = 0;
                if (!dfs(adj, i, cycle, n)) {
                    return false;
                }
                adj[node][i] = 1;
                adj[i][node] = 1;
            }
        }
        return true;
    }
};
