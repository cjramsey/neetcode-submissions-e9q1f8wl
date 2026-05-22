class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> a, const vector<int> b) {
                return a[0] < b[0];
            }
        );
        vector<vector<int>> res;
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > r) {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else {
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
        }
        res.push_back({l, r});
        return res;
    }
};
