class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // rotation by 90 degree clockwise is equivalent to
        // transpose + reflection in y-axis through centre

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < (n / 2); ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[j][i], matrix[j][n - i - 1]);
            }
        }
    }
};
