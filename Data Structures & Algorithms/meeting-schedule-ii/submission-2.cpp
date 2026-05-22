/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<vector<int>> time;
        for (const auto& interval: intervals) {
            time.push_back({interval.start, 1});
            time.push_back({interval.end, -1});
        }

        sort(time.begin(), time.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return tie(a[0], a[1]) < tie(b[0], b[1]);
            }
        );

        int count = 0, res = 0;
        for (const auto& event: time) {
            count += event[1];
            res = max(res, count);
        }

        return res;
    }
};
