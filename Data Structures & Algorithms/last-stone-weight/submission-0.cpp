class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> max_heap{stones.begin(), stones.end()};
        while (max_heap.size() > 1) {
            int first = max_heap.top();
            max_heap.pop();
            int second = max_heap.top();
            max_heap.pop();
            if (first == second) {
                continue;
            }
            else {
                max_heap.push(abs(first - second));
            }
        }
        if (max_heap.empty()) {
            return 0;
        }
        return max_heap.top();
    }
};
