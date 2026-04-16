class Solution {
public:
    vector<vector<string>> res; 
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols(n, 0);
        vector<int> pos(2*n, 0);
        vector<int> neg(2*n, 0);
        backtrack({}, 0, n, cols, pos, neg);
        return res;
    }

private:

    void backtrack(vector<string> board, int row, int n, vector<int>& cols, vector<int>& pos, vector<int>& neg) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        string cur_row(n, '.');
        board.push_back(cur_row);
        for (int i = 0; i < n; ++i) {
            if (cols[i] || pos[row + i] || neg[row - i + n]) {
                continue;
            }
            board[row][i] = 'Q';
            cols[i] = 1;
            pos[row + i] = 1;
            neg[row - i + n] = 1;
            backtrack(board, row + 1, n, cols, pos, neg);
            cols[i] = 0;
            pos[row + i] = 0;
            neg[row - i + n] = 0;
            board[row][i] = '.';
        }
    }
};
