class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, {}, 0, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, vector<int> comb, int total, int index) {
        if (total == target) {
            res.push_back(comb);
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (total + candidates[i] > target) {
                break;
            }

            comb.push_back(candidates[i]);
            backtrack(candidates, target, comb, total + candidates[i], i + 1);
            comb.pop_back();
        }
    }
};
