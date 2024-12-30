class MinStack {
public:
    vector<pair<int, int>> min_stack;
    MinStack() {
    }
    
    void push(int val) {
        // grab current minimum
        int cur_min = min_stack.size() ? getMin() : val;
        // update minimum based on new value being pushed 
        int min = (val < cur_min) ? val : cur_min;
        // push new pair
        min_stack.push_back({val, min});
    }
    
    void pop() {
        min_stack.pop_back();
    }
    
    int top() {
        return min_stack[min_stack.size() - 1].first;  
    }
    
    int getMin() {
        return min_stack[min_stack.size() - 1].second;
    }
};
