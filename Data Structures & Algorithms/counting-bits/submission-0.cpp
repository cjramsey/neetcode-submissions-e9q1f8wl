class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int cur = i;
            while (cur > 0) {
                count += cur & 1;
                cur >>= 1;
            }
            res.push_back(count);
        }
        return res;
    }
};
