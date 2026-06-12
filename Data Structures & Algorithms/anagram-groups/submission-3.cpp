class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long, vector<string>> mapping;
        for (const auto& s: strs) {
            long key = 0;
            for (char c: s) {
                key += integerPow(26, c - 'a' + 1);
            }
            mapping[key].push_back(s);
        }
        
        vector<vector<string>> res;
        for (const auto&[k, group]: mapping) {
            res.push_back(group);
        }
        return res;
    }

private:
    long integerPow(int base, int exp) {
        if (exp == 0) {
            return 1;
        }
        if (exp == 1) {
            return base;
        }
        if (exp % 2 == 0) {
            return integerPow(base * base, exp / 2);
        }
        return static_cast<long>(base) * integerPow(base * base, exp / 2);
    }
};
