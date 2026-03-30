#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;

        for (char c:  s) {
            if (c == '(' || c == '[' || c == '{') {
                stack_.push(c);
            }
            else if (c == ')') {
                if (stack_.empty()) return false;
                if (stack_.top() == '(') {
                    stack_.pop();
                }
                else {
                    return false;
                }
            }
            else if (c == ']') {
                if (stack_.empty()) return false;
                if (stack_.top() == '[') {
                    stack_.pop();
                }
                else {
                    return false;
                }
            }
            else if (c == '}') {
                if (stack_.empty()) return false;
                if (stack_.top() == '{') {
                    stack_.pop();
                }
                else {
                    return false;
                }
            }
        }   
        return (stack_.empty());     
    }
};
