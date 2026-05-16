class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                open.push(i);
            }
            else if (s[i] == '*') {
                star.push(i);
            }
            else {
                if (open.empty() && star.empty()) {
                    return false;
                }
                else if (!open.empty()) {
                    open.pop();
                }
                else {
                    star.pop();
                }
            }
        }

        while (!open.empty()) {
            if (star.empty()) {
                return false;
            }
            if (open.top() > star.top()) {
                return false;
            }
            open.pop();
            star.pop();
        }
        return true;
    }
};
