class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0] && backtrack(board, word, 1, i, j)) {
                    return true;
                }
            }
        } 
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int i, int row, int col) {
        if (i == word.length()) {
            return true;
        }
        auto cell = board[row][col];
        board[row][col] = '#';
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (const auto& d: directions) {
            if (row + d[0] < 0 
                || row + d[0] >= board.size()
                || col + d[1] < 0 
                || col + d[1] >= board[0].size()
                || board[row + d[0]][col + d[1]] == '#'
            ) {
                continue;
            }
            if (board[row + d[0]][col + d[1]] == word[i]) {
                bool found = backtrack(board, word, i + 1, row + d[0], col + d[1]);
                if (found) {
                    return true;
                }
            } 
        }
        board[row][col] = cell;
        return false;
    }
};
