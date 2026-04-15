class Solution {
public:
    vector<vector<string>> res{};
    vector<vector<string>> partition(string s) {
        backtrack(s, "", {}, 0);
        return res;
    }

    void backtrack(string s, string cur_word, vector<string> cur_path, int i) {
        if (i == s.length()) {
            if (!cur_word.length()) {
                res.push_back(cur_path);
            }
            return;
        }
        cur_word += s[i];
        ++i;

        if (palindrome(cur_word)) {
            cur_path.push_back(cur_word);
            backtrack(s, "", cur_path, i);
            cur_path.pop_back();
        }
        backtrack(s, cur_word, cur_path, i);
    }

    bool palindrome(string s) {
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
