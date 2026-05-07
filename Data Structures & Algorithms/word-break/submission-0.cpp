class Solution {
public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()] = true;
        return dfs(0, wordDict, s);
    }

    bool dfs(int i, vector<string>& wordDict, string& s) {
        if (memo.contains(i)) {
            return memo[i];
        }

        for (string& w: wordDict) {
            if (s.substr(i, w.length()) == w) {
                if (dfs(i + w.length(), wordDict, s)) {
                    memo[i] = true;
                    return true;
                }
            }
        }
        memo[i] = false;
        return false;
    }
};
