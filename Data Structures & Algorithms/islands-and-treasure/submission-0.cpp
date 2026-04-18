class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        unsigned int inf = 2147483647;
        vector<vector<int>> directions{ {1,0}, {-1,0}, {0,1}, {0,-1} };
        queue<vector<int>> q;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                vector<int> coord = q.front();
                int row = coord[0];
                int col = coord[1];
                q.pop();

                for (const auto& d: directions) {
                    int new_row = row + d[0];
                    int new_col = col + d[1];
                    if (new_row < 0 || new_row >= grid.size()
                        || new_col < 0 || new_col >= grid[0].size()) {
                        continue;
                    }
                    if (grid[new_row][new_col] == inf) {
                        grid[new_row][new_col] = time;
                        q.push({new_row, new_col});
                    }
                }
            }
            ++time;
        }
        return;
    }
};
