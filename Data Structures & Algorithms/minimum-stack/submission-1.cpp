class MinStack {
public:
    vector<pair<int, int>> st;
    int minimum;

    MinStack() 
        : st{}, minimum{numeric_limits<int>::max()}
    {    
    }
    
    void push(int val) {
        st.push_back({val, minimum});
        minimum = min(minimum, val);
    }
    
    void pop() {
        minimum = st.back().second;
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return minimum;
    }
};
