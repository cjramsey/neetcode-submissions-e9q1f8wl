class MedianFinder {
public:
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int count;

    MedianFinder() : count{0}
    {
    }
    
    void addNum(int num) {
        min_heap.push(num);
        if (!max_heap.empty()) {
            while (min_heap.top() < max_heap.top()) {
                int smaller = min_heap.top();
                min_heap.pop();
                int bigger = max_heap.top();
                max_heap.pop();
                min_heap.push(bigger);
                max_heap.push(smaller);
            }
        }
        while (min_heap.size() > max_heap.size() + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        ++count;
    }
    
    double findMedian() {
        if (count % 2 == 0) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
        else {
            return (min_heap.top());
        }
    }
};
