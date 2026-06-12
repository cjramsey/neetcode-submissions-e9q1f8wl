public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int[,] rows = new int[9, 9];
        int[,] cols = new int[9, 9];
        int[,] squares = new int[9, 9];

        int N = 9;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                int digit = board[r][c] - '1';
                if (rows[r, digit] == 1 
                    || cols[c, digit] == 1 
                    || squares[(c / 3) * 3 + (r / 3), digit] == 1) {
                    return false;
                }
                rows[r, digit] = 1;
                cols[c, digit] = 1;
                squares[(c / 3) * 3 + (r / 3), digit] = 1;
            }
        }
        return true;
    }
}
