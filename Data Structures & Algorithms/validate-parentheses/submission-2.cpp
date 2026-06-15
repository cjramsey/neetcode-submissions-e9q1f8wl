class Solution {
public:
    unordered_map<char, char> mapping{
        {')' ,'('},
        {']', '['},
        {'}', '{'}
    };

    bool isValid(string s) {
        stack<char> st{};
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
                continue;
            }

            if (st.empty()) {
                return false;
            }
            if (st.top() != mapping[c]) {
                return false;
            }
            st.pop();
        }
        return st.empty();
    }
};
