#include <array>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> groups{};

        for (const auto& s: strs)
        {
            array<int, 26> arr{};
            for (const auto& c: s)
            {
                ++arr[static_cast<int>(c) - 'a'];
            }

            if (!groups.contains(arr)) groups[arr] = {};
            groups[arr].push_back(s);
        }
        
        vector<vector<string>> result{};
        for (const auto& entry: groups)
        {
            result.push_back(entry.second);
        }
        return result;
    }
};
