class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) : parent(n + 1), rank(n + 1, 1) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        parent[i] =  find(parent[i]);
        return parent[i];
    }

    bool unite(int i, int j) {
        int s1 = find(i);
        int s2 = find(j);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                ++rank[s1];
            }
            return true;    // returns true if union occurred
        }
        return false;   // returns false if points already connected
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<array<int, 3>> edges;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            } 
        }

        sort(edges.begin(), edges.end());
        int res = 0;

        for (const auto&[dist, i, j]: edges) {
            if (dsu.unite(i, j)) {
                res += dist;
            }
        }
        return res;
    }
};
