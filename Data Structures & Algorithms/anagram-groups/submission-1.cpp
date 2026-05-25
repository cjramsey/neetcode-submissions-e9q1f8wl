class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto s: strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            groups[copy].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto& [_, group]: groups) {
            res.emplace_back(group);
        }
        return res;
    }
};
