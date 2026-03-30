class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        unordered_map<char, int> count;
        for (char c: t) {
            ++count[c];
        }

        std::string res(s.length() + 1, '*');
        unordered_map<char, int> window;
        int need = count.size();
        int have = 0;
        int l = 0;
        for (int r = 0; r < s.length(); ++r) {
            ++window[s[r]];
            if (window[s[r]] == count[s[r]]) {
                ++have;
            }
            
            if (have == need && res.length() > r - l + 1)
                res = s.substr(l, r - l + 1);
            
            while (l < r && have == need) {
                if (res.length() > r - l + 1)
                    res = s.substr(l, r - l + 1);
                --window[s[l]];
                if (window[s[l]] == count[s[l]] - 1) {
                    --have;
                }
                ++l;
            }
            if (have == need && res.length() > r - l + 1)
                res = s.substr(l, r - l + 1);
        }
        if (res.length() == s.length() + 1) {
            return "";
        }

        return res;
    }
};
