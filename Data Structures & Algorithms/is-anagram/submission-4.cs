public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> freq_s = new();
        Dictionary<char, int> freq_t = new();

        foreach (char c in s) {
            if (!freq_s.ContainsKey(c)) {
                freq_s[c] = 1;
            }
            ++freq_s[c];
        }
        foreach (char c in t) {
            if (!freq_t.ContainsKey(c)) {
                freq_t[c] = 1;
            }
            ++freq_t[c];
        }

        if (freq_s.Count != freq_t.Count) {
            return false;
        }

        foreach (var (key, count) in freq_s) {
            if (!freq_t.ContainsKey(key) || freq_t[key] != count) { 
                return false;
            }
        }
        return true;
    }
}
