class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = m - 1; i >= 0; --i) {
            if (text1[i] == text2[n - 1]) {
                while (i >= 0) {
                    dp[i][n - 1] = 1;
                    --i;
                }
                break;
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            if (text1[m - 1] == text2[j]) {
                while (j >= 0) {
                    dp[m - 1][j] = 1;
                    --j;
                }
                break;
            }
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
