class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<array<int, 9>, 10> rows{};    // 10 makes indexing more convenient
        array<array<int, 9>, 10> cols{};    // digits run from 1 - 9 not 0 - 8
        array<array<int, 9>, 10> squares{};
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int digit = board[i][j] - '0';
                if (rows[i][digit] != 0 || cols[j][digit] != 0 || squares[(i / 3) * 3 + (j / 3)][digit] != 0) {
                    return false;
                }
                rows[i][digit] = 1;
                cols[j][digit] = 1;
                squares[(i / 3) * 3 + (j / 3)][digit] = 1;
            }
        }
        return true;
    }
};
