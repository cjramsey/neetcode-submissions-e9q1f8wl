class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> s_freq;
        unordered_map<char, int> t_freq;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            ++s_freq[s[i]];
            ++t_freq[t[i]];
        }
        if (s_freq.size() != t_freq.size()) {
            return false;
        }
        for (const auto& [c, count]: s_freq) {
            if (t_freq[c] != count) {
                return false;
            }
        }
        return true;
    }
};
