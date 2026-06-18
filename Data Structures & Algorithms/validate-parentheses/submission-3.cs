public class Solution {
    public bool IsValid(string s) {
        Stack<char> st = new();

        Dictionary<char, char> map = new Dictionary<char, char>()
        {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        foreach (char c in s) {
            if (map.ContainsKey(c)) {
                if (st.Count > 0 && st.Peek() == map[c]) {
                    st.Pop();
                }
                else {
                    return false;
                }
            }
            else {
                st.Push(c);
            }
        }
        return st.Count == 0;
    }
}
