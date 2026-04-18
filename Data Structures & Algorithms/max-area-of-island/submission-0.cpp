class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    int count = 0;
                    dfs(grid, row, col, count);
                    if (count > res) {
                        res = count;
                    }
                }
            }
        } 
        return res;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& count) {
        ++count;
        grid[row][col] = 0;
        vector<vector<int>> directions{ {1,0}, {-1,0}, {0,1}, {0,-1} };
        for (const auto& d: directions) {
            if (row + d[0] < 0 || row + d[0] >= grid.size()
                || col + d[1] < 0 || col + d[1] >= grid[0].size()) {
                    continue;
                }
            if (grid[row + d[0]][col + d[1]] == 1) {
                dfs(grid, row + d[0], col + d[1], count);
            }
        }
    }
};
