class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        unsigned int inf = 2147483647;

        int m = grid.size();
        int n = grid[0].size();
    
        queue<pair<int, int>> q;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }

        vector<vector<int>> directions{ {1,0}, {-1,0}, {0,1}, {0,-1} };

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (const auto& dir: directions) {
                int r = row + dir[0];
                int c = col + dir[1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != inf) {
                    continue;
                }

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }            
        }
    }
};
