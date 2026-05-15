class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            last_index[s[i] - 'a'] = i;
        }

        vector<int> res;
        int size = 1;
        int max_index = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            max_index = max(max_index, last_index[s[i] - 'a']);
            if (max_index == i) {
                res.push_back(size);
                size = 1;
                max_index = 0;
                continue;
            }
            ++size;
        }
        return res;
    }
};
