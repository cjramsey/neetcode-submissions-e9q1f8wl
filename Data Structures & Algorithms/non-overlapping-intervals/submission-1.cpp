class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> a, const vector<int> b) {
                return a[0] < b[0];
            });
        int prevEnd = std::numeric_limits<int>::min();
        int res = 0;
        for (const auto& interval: intervals) {
            if (prevEnd <= interval[0]) {
                prevEnd = interval[1];
            }
            else {
                prevEnd = min(prevEnd, interval[1]);
                ++res;
            }
        }
        return res;
    }
};
