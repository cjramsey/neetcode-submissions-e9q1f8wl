class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](vector<int>& left, vector<int>& right) {
            return (left[0]*left[0] + left[1]*left[1]
                    > right[0]*right[0] + right[1]*right[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> min_heap(points.begin(), points.end(), comp);

        vector<vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.emplace_back(min_heap.top());
            min_heap.pop();
        }
        return res;
    }
};
