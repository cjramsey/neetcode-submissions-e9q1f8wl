#include <queue>
#include <vector>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> max_heap;

        for (int r = 0; r < k; ++r) {
            max_heap.push({nums[r], r});
        }

        res.push_back(max_heap.top().first);

        int l = 0;
        for (int r = k; r < nums.size(); ++r) {
            max_heap.push({nums[r], r});

            while (max_heap.top().second <= l) {
                max_heap.pop();
            }
            ++l;

            res.push_back(max_heap.top().first);
        }

        return res;
    }
};
