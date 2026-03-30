#include <unordered_set>

class Solution {
public:
    int getSquare(int i, int j) {
        return ((i / 3) * 3) + j / 3;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> squares;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char cur = board[i][j];
                if (cur == '.') continue;
                
                int cur_sq = getSquare(i, j);

                if (rows.contains(i)) {
                    if (rows[i].contains(cur))
                        return false;
                    rows[i].insert(cur);
                }
                else
                    rows[i] = {cur};

                if (cols.contains(j)) {
                    if (cols[j].contains(cur))
                        return false;
                    cols[j].insert(cur);
                }
                else
                    cols[j] = {cur};

                if (squares.contains(cur_sq)) {
                    if (squares[cur_sq].contains(cur))
                        return false;
                    squares[cur_sq].insert(cur);
                }
                else
                    squares[cur_sq] = {cur};
            }
        }
        return true;
    }
};
