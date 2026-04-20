class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> lookup1;
        vector<int> row(n, 0);
        for (int i = 0; i < m; ++i) {
            lookup1.push_back(row);
        }
        vector<vector<int>> lookup2{lookup1};
        for (int i = 0; i < m; ++i) {
            dfs(heights, lookup1, i, 0);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, lookup1, 0, j);
        }
        for (int i = 0; i < m; ++i) {
            dfs(heights, lookup2, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            dfs(heights, lookup2, m - 1, j);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lookup1[i][j] == 1 && lookup2[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& lookup, int row, int col) {
        if (lookup[row][col] != 0) {
            return;
        }
        ++lookup[row][col];
        
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& v: directions) {
            int r = row + v[0];
            int c = col + v[1];
            if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size()) {
                continue;
            }
            if (heights[row][col] > heights[r][c]) {
                continue;
            }
            dfs(heights, lookup, r, c);
        }
    }
};
