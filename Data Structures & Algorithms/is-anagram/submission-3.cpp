class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq_s, freq_t;
        for (char c: s) {
            ++freq_s[c];
        } 
        for (char c: t) {
            ++freq_t[c];
        }
        if (freq_s.size() != freq_t.size()) {
            return false;
        }

        for (const auto&[letter, count]: freq_s) {
            if (freq_t[letter] != count) {
                return false;
            }
        }
        return true;
    }
};
