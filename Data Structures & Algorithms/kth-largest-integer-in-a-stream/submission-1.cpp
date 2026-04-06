class KthLargest {
public:
    int k_;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    KthLargest(int k, vector<int>& nums) 
    {
        k_ = k;
        for (const auto& n: nums) {
            min_heap.push(n);
            if (min_heap.size() > k_) {
                min_heap.pop();
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k_) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
