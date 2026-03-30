#include <array>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int res = 0;
        unordered_set<char> characters{};

        while (r < s.length())
        {
            while (l < r && characters.contains(s[r]))
            {
                characters.erase(s[l]);
                ++l;
            }
            characters.insert(s[r]);
            res = max(res, r - l + 1);
            ++r;
        }  
        return res;
    }
};
