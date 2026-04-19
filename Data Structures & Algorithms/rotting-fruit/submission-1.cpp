class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rotten.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        int time = 0;
        vector<pair<int, int>> directions {
            {1,0},{-1,0},{0,1},{0,-1}
        };

        while (!rotten.empty() && fresh > 0) {
            int len = rotten.size();

            for (int i = 0; i < len; ++i) {
                int r = rotten.front().first;
                int c = rotten.front().second;
                rotten.pop();

                for (const auto& d: directions) {
                    int row = r + d.first;
                    int col = c + d.second;
                    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1) {
                        continue;
                    }
                    grid[row][col] = 2;
                    --fresh;
                    rotten.push({row, col});
                }
            }
            ++time;
        }
        return (fresh == 0 ? time : -1);
    }
};
