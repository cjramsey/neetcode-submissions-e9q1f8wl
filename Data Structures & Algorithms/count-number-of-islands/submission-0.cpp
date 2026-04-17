class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    ++res;
                    dfs(grid, row, col);
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        grid[row][col] = '0';
        for (const auto& d: directions) {
            if (row + d[0] < 0 || row + d[0] >= grid.size()
                || col + d[1] < 0|| col + d[1] > grid[0].size()) {
                continue;
            }
            if (grid[row + d[0]][col + d[1]] == '1') {
                dfs(grid, row + d[0], col + d[1]);
            }
        }
    }
};
