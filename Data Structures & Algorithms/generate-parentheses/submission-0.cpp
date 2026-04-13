class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        helper("", 2*n, 0, 0);
        return res;
    }

    void helper(string cur, int remaining, int open, int close) {
        if (open < close || open > remaining + close) {
            return;
        }
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }

        helper(cur + '(', --remaining, open + 1, close);
        helper(cur + ')', remaining, open, close + 1);
    }
};
