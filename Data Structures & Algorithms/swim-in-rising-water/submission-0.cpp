class Solution {
public:
    struct {
        bool operator()(const vector<int> l, const vector<int> r) {
            return l[0] > r[0];
        }
    } comp;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> q(comp);
        q.push({grid[0][0], 0, 0});

        int t = 0;
        while (q.size() > 0) {
            vector<int> cell = q.top();
            q.pop();
            int height = cell[0];
            int r = cell[1];
            int c = cell[2];
            t = max(t, height);
            if (r == n - 1 && c == n - 1) {
                return t;
            }
            grid[r][c] = -1;    // marking cell as visited
            for (const auto& d: directions) {
                int row = r + d[0];
                int col = c + d[1];
                if (row < 0 || row >= n || col < 0 || col >= n || grid[row][col] == -1) {
                    continue;
                }
                q.push({grid[row][col], row, col});
            }
        }
        return 0;
    }
};
