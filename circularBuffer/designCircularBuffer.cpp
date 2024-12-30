class MyCircularQueue {
public:
    int cap;
    int cur_size;
    int* arr;
    int head;
    int tail;

    MyCircularQueue(int k) {
        arr = (int*)malloc(sizeof(int) * k);
        cap = k;
        cur_size = 0;
        head = 0;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail + 1) % cap;
        arr[tail] = value;
        cur_size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        head = (head + 1) % cap;
        cur_size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : arr[head]; 
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[tail];
    }
    
    bool isEmpty() {
        return cur_size == 0 ? true : false;
    }
    
    bool isFull() {
        return cur_size == cap ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */