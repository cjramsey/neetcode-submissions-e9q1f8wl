class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;

        for (const auto& c: s1) {
            ++count1[c];
        }

        int need = count1.size();
        int have = 0;

        unordered_map<char, int> window_count;
        int l = 0;
        int r  = 0;
        while (r < s1.length() && r < s2.length()) {
            ++window_count[s2[r]];

            if (window_count[s2[r]] == count1[s2[r]])
                ++have;
            
            ++r;
        }

        if (have == need) return true;

        while (r < s2.length()) {
            ++window_count[s2[r]];
            if (window_count[s2[r]] == count1[s2[r]])
                ++have;
            ++r;

            --window_count[s2[l]];
            if (window_count[s2[l]] == count1[s2[l]] - 1)
                --have;
            ++l;
            
            if (have == need) return true;
        }
        return false;
    }
};
