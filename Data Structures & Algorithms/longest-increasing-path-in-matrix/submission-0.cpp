class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(i, j, matrix, dp));
            }
        }
        return res;
    }

    // Return the longest increasing path starting at (row, col)
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) { 
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int cell = matrix[row][col];

        int res = 1;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& [dr, dc]: directions) {
            int r = row + dr;
            int c = col + dc;
            if ((0 <= r) && (r < m) && (0 <= c) && (c < n)) {
                if (cell < matrix[r][c]) {
                    res = max(res, 1 + dfs(r, c, matrix, dp));
                } 
            }
        }
        dp[row][col] = res;
        return res;
    }
};
