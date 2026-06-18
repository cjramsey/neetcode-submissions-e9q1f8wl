class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st{};
        unordered_set<char> ops = {'+', '-', '*', '/'};

        for (const auto& token: tokens) {
            if (token.size()  == 1) {
                char op = token[0];
                if (ops.contains(op)) {
                    int right = st.top();
                    st.pop();
                    int left = st.top();
                    st.pop();
                    switch (op)
                    {
                        case '+':
                            st.push(left + right);
                            break;
                        case '-':
                            st.push(left - right);
                            break;
                        case '*':
                            st.push(left * right);
                            break;
                        case '/':
                            st.push(left / right);
                            break;
                    }
                }
                else {
                    st.push(stoi(token));
                }
            }
            else {
                if (token[0] == '-') {
                    st.push(-1 * stoi(token.substr(1)));
                }
                else {
                    st.push(stoi(token));
                }
            }
        }
        return st.top();
    }
};
