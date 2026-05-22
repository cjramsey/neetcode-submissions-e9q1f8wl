class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }    
        );

        vector<int> res;
        for (int query: queries) {
            priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                greater<tuple<int, int>>> min_heap;
            int i = 0;
            while (i < intervals.size() && intervals[i][0] <= query)  {
                min_heap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }

            while (!min_heap.empty() && get<1>(min_heap.top()) < query) {
                min_heap.pop();
            }

            if (!min_heap.empty()) {
                res.push_back(get<0>(min_heap.top()));
            }
            else {
                res.push_back(-1);
            }
        }

        return res;
    }
};
