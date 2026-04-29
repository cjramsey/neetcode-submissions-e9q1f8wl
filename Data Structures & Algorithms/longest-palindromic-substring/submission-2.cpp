class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res.length()) {
                    res = s.substr(l, r - l + 1);
                }
                --l;
                ++r;
            }
            // even length 
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res.length()) {
                    res = s.substr(l, r - l + 1);
                }
                --l;
                ++r;
            }
        }
        return res;
    }
};
