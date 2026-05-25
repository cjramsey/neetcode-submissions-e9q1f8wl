class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        int sum3 = accumulate(s3.begin(), s3.end(), 0);

        if (sum1 + sum2 != sum3) {
            return false;
        }

        int m = s1.size();
        int n = s2.size();

        // dp[i][j] true if s3[i + j:] can be formed from s1[i:] and s2[j:]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m - 1; i >= 0; --i) {
            if (s1[i] == s3[i + n] && dp[i + 1][n]) {
                dp[i][n] = true;
            }
            else {
                break;
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            if (s2[j] == s3[m + j] && dp[m][j + 1]) {
                dp[m][j] = true;
            }
            else {
                break;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};
