#include <unordered_map>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;

        for (const auto& n: nums)
            numSet.insert(n);

        int longest = 0;

        for (const auto& n: nums)
        {
            if (!numSet.contains(n - 1))
            {
                int length = 1;
                while (numSet.contains(n + length))
                    ++length;
                
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
