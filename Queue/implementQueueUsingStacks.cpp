class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(this -> empty()){
            return -1;
        }
        // pop s1 contents into s2
        while(s1.size()){
            int n = s1.top();
            s1.pop();
            
            s2.push(n);
        }
        // grab top of s2 and store for return
        int res = s2.top();
        // pop top of s2
        s2.pop();
        // pop s2 contents into s1
        while(s2.size()){
            int n = s2.top();
            s2.pop();

            s1.push(n);
        }
        // return res
        return res;
    }
    
    int peek() {
        if(this -> empty()){
            return -1;
        }
        // pop s1 contents into s2
        while(s1.size()){
            int n = s1.top();
            s1.pop();
            
            s2.push(n);
        }
        // grab top of s2 and store for return
        int res = s2.top();

        // pop s2 contents into s1
        while(s2.size()){
            int n = s2.top();
            s2.pop();

            s1.push(n);
        }
        // return res
        return res;       
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
