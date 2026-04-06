class KthLargest {
public:
    int k_;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    KthLargest(int k, vector<int>& nums) 
        : min_heap{nums.begin(), nums.end()}
        , k_{k}
    {
    }
    
    int add(int val) {
        min_heap.push(val);
        while (min_heap.size() > k_) {
            min_heap.pop();
        }
        return min_heap.top();
    }
};
