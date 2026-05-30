class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        return dfs(m - 1, n - 1, s, p);
    }

    bool dfs(int i, int j, string& s, string& p) {
        if (i == -1 && j == -1) {   // both strings complete
            return true;
        }
        if (j == -1) {  // string remains but pattern complete
            return false;
        }
        if (i == -1) {  // pattern remains but string complete
            if (p[j] == '*') {  // need to be able to match zero with '*'
                return dfs(i, j - 2, s, p);
            }
            return false;
        }

        if (p[j] != '.' && p[j] != '*') {   // pattern is actual letter
            if (s[i] == p[j]) { // must match current char
                return dfs(i - 1, j - 1, s, p);
            }
            return false;
        }

        if (p[j] == '.') {  // match the letter
            return dfs(i - 1, j - 1, s, p);
        }

        // the current character is '*'
        if (dfs(i, j - 2, s, p)) {   // match zero of preceding char
            return true;
        }
        char preceding = p[j - 1];  // guaranteed to be in range
        if (preceding == '.') {
            while (i >= 0) {    // take as many '.' as possible
                if (dfs(i - 1, j - 2, s, p)) {
                    return true;
                }
                --i;
            }
        }
        else {  // can the current char as many times as possible
            while (i >= 0 && s[i] == preceding) {  
                if (dfs(i - 1, j - 2, s, p)) {
                    return true;
                }
                --i;
            }
        }
        return false;
    }
};
