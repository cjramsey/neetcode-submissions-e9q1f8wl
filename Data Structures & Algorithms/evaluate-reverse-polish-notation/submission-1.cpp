#include <cctype>
#include <cstdlib>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack_;

        for (const auto& c: tokens) {
            int n1;
            int n2;
            if (c == "+") {
                n1 = stack_.top();
                stack_.pop();
                n2 = stack_.top();
                stack_.pop();
                stack_.push(n1 + n2);
            }
            else if (c == "-") {
                n1 = stack_.top();
                stack_.pop();
                n2 = stack_.top();
                stack_.pop();
                stack_.push(n2 - n1);
            }
            else if (c == "*") {
                n1 = stack_.top();
                stack_.pop();
                n2 = stack_.top();
                stack_.pop();
                stack_.push(n1 * n2);
            }
            else if (c == "/") {
                n1 = stack_.top();
                stack_.pop();
                n2 = stack_.top();
                stack_.pop();
                stack_.push(n2 / n1);
            }
            else {
                stack_.push(atoi(c.c_str()));
            }
            cout << stack_.top();
        }
        return stack_.top();
    }
};
