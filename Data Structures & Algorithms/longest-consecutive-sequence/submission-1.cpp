class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int n: nums) {
            numSet.insert(n);
        }
        int res = 0;
        for (int n: numSet) {
            if (!numSet.contains(n - 1)) {
                int length = 1;
                while (numSet.contains(n + length)) {
                    ++length;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
