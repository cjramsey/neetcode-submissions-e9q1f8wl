class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> res(3, false);
        for (const auto& triplet: triplets) {
            if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) {
                continue;
            }
            for (int i = 0; i < 3; ++i) {
                if (triplet[i] == target[i]) {
                    res[i] = true;
                }
            }
        }
        for (bool b: res) {
            if (!b) {
                return false;
            }
        }
        return true;
    }
};
