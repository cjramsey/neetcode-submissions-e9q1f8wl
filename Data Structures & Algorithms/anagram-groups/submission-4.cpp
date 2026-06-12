class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& s: strs) {
            vector<int> freq(26, 0);
            for (char c: s) {
                ++freq[c - 'a'];
            }
            string key = "";
            for (int n: freq) {
                key += '#' + n;
            }
            groups[key].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto&[_, group]: groups) {
            res.push_back(group);
        }
        return res;
    }
};
