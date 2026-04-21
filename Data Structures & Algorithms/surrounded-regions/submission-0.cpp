class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int row = 0; row < m; ++row) {
            if (board[row][0] == 'O') {
                dfs(board, row, 0);
            }
            if (board[row][n - 1] == 'O') {
                dfs(board, row, n - 1);
            }
        }
        for (int col = 1; col < n - 1; ++col) {
            if (board[0][col] == 'O') {
                dfs(board, 0, col);
            }
            if (board[m - 1][col] == 'O') {
                dfs(board, m - 1, col);
            }
        }

        // Replace all 'T' with 'O' and all 'O' with 'X'
        for (auto& row: board) {
            for (char& cell: row) {
                if (cell == 'T') {
                    cell = 'O';
                }
                else if (cell == 'O') {
                    cell = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        board[row][col] = 'T';  // set edge groups to T temporarily

        vector<pair<int, int>> directions{
            {1,0},{-1,0},{0,1},{0,-1}
        };
        for (const auto& d: directions) {
            int r = row + d.first;
            int c = col + d.second;
            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
                continue;
            }
            if (board[r][c] == 'O') {
                dfs(board, r, c);
            }
        }
    }
};
