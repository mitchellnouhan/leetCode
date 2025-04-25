class MovingAverage {
public:
    queue<int> q;
    int cap;
    double sum;
    double size;

    MovingAverage(int size) {
        this -> cap = size;
        this -> sum = 0;
        this -> size = 0;
    }
    
    double next(int val) {
        this -> q.push(val);
        this -> sum += val;
        this -> size++;

        if(this -> size > this -> cap){
            // pop front of the queue
            int front = q.front();
            q.pop();

            // update class vars
            this -> size--;
            this -> sum -= front;
        }
        return (this -> sum / this -> size);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */