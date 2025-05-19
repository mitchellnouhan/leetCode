class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(this -> empty()){
            return -1;
        }
        int res;
        
        while(q1.size() > 1){
            int n = q1.front();
            q1.pop();

            q2.push(n);
        }
        
        res = q1.front();
        q1.pop();

        while(q2.size()){
            int n = q2.front();
            q2.pop();

            q1.push(n);
        }

        return res;
    }
    
    int top() {
        if(this -> empty()){
            return -1;
        }
        int res;
        
        while(q1.size() > 1){
            int n = q1.front();
            q1.pop();
            
            q2.push(n);
        }

        res = q1.front();
        q1.pop();

        q2.push(res);

        while(q2.size()){
            int n = q2.front();
            q2.pop();

            q1.push(n);
        }

        return res;  
    }
    
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */