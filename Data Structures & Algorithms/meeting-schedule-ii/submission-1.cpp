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
        vector<int> start{};
        vector<int> end{};

        for (const auto& interval: intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int s = 0;
        int count = 1;
        int res = 0;
        for (int e = 0; e < end.size(); ++e) {
            while (s < start.size() && start[s] < end[e]) {
                ++count;
                ++s;
            }
            --count;
            res = max(res, count);
        }
        return res;
    }
};
