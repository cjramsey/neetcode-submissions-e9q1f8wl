class Solution {
public:

    string encode(vector<string>& strs) {
        // use length + 
        string res;
        for (const auto& s: strs) {
            int n = s.size();
            res += to_string(n) + '_' + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i = 0;
        while (i < n) {
            string digits;
            while (i < n && s[i] != '_') {
                digits += s[i];
                ++i;
            }
            ++i;    // skip underscore delimiter
            int length = stoi(digits);
            res.push_back(s.substr(i, length));
            i += length;
        }
        return res;
    }
};
