class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        vector<int> res{};

        int i = 0, j = 0;
        while (res.size() < m * n) {
            while (j <= right) {
                res.push_back(matrix[i][j]);
                ++j;
            }
            ++top;
            ++i;
            --j;

            if (res.size() == m * n) break;

            while (i <= bottom) {
                res.push_back(matrix[i][j]);
                ++i;
            }
            --right;
            --i;
            --j;

            if (res.size() == m * n) break;

            while (j >= left) {
                res.push_back(matrix[i][j]);
                --j;
            }
            --bottom;
            --i;
            ++j;

            if (res.size() ==  m * n) break;

            while (i >= top) {
                res.push_back(matrix[i][j]);
                --i;
            }
            ++left;
            ++i;
            ++j;
        }

        return res;
    }
};
