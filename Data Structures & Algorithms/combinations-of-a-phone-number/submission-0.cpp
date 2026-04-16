class Solution {
public:
    unordered_map<char, string> digit_map{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (!digits.length()) {
            return {};
        }
        backtrack(digits, 0, {});
        return res;
    }

    void backtrack(string& digits, int i, string cur) {
        if (i == digits.length()) {
            res.push_back(cur);
            return;
        }
        for (const auto& c: digit_map[digits[i]]) {
            backtrack(digits, i + 1, cur + c);
        }
    }
};
