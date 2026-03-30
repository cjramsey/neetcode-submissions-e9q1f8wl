#include <stack>
#include <utility>
#include <limits>

class MinStack {
public:
    int min_;
    stack<pair<int, int>> stack_;

    MinStack() 
        : min_{std::numeric_limits<int>::max()}
    {
    }
    
    void push(int val) {
        stack_.push({val, min_});
        min_ = min(val, min_);
    }
    
    void pop() {
        min_ = stack_.top().second;
        stack_.pop();
    }
    
    int top() {
        return stack_.top().first;
    }
    
    int getMin() {
        return min_;
    }
};
