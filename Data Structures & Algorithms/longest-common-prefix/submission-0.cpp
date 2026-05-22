class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string substr = strs[0];
        while (substr.length() > 0) {
            int valid = true;
            for (const auto& word: strs) {
                if (!word.starts_with(substr)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return substr;
            }
            substr.pop_back();
        }
        return "";
    }
};