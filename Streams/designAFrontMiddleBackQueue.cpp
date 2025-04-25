class Node{
public:
    int val;
    Node* prev;
    Node* next;

    Node(int val){
        this -> val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class FrontMiddleBackQueue {
public:
    Node* f;
    Node* m;
    Node* b;
    int size;

    void printQueue(){
        cout << "printing queue:\n";
        if(f)
            cout << "f: " << f -> val << "\n";
        else
            cout << "f: null\n"; 
        if(m)
            cout << "m: " << m -> val << "\n";
        else
            cout << "m: null\n";
        if(b)
            cout << "b: " << b -> val << "\n";
        else
            cout << "b: null\n";

        Node* tmp = f;
        for(int i = 0; i < size; i++){
            cout << tmp -> val << " ";
            tmp = tmp -> next;
        }
        cout << "\n\n";
    }

    bool isQueueEmpty(){
        return (f == nullptr && m == nullptr && b == nullptr);
    }

    void createGenesisNode(int val){
        Node* t = new Node(val);
        f = t;
        m = t;
        b = t;
        size++;
    }

    FrontMiddleBackQueue() {
        f = nullptr;
        m = nullptr;
        b = nullptr;
        size = 0;
    }
    
    void pushFront(int val) {
        if(isQueueEmpty()){
            createGenesisNode(val);
            //printQueue();
            return;
        }

        Node* t = new Node(val);
    
        // attach to queue
        t -> next = f;

        // update front
        f -> prev = t;
        f = t;

        //update middle
        if(size % 2){
            m = m -> prev;
        }

        // update size
        size++;

        //printQueue();
    }
    
    void pushMiddle(int val) {
        if(isQueueEmpty()){
            createGenesisNode(val);
            //printQueue();
            return;
        }

        Node* t = new Node(val);

        // if odd sized queue, push middle forward
        if(size == 1){
            // attach t
            t -> next = m;
            m -> prev = t;

            // update m
            m = t;

            // update f
            f = t;
        }
        else if(size % 2){
            // attach t
            t -> next = m;
            t -> prev = m -> prev;

            m -> prev = t;
            (t -> prev) -> next = t;

            // update m
            m = t;
        }
        // if even sized queue, push middle back
        else{
            // attach t
            t -> prev = m;
            t -> next = m -> next;

            m -> next = t;
            (t -> next) -> prev = t;  

            // update m
            m = t;
        }
        // update size
        size++;

        //printQueue();       
    }
    
    void pushBack(int val) {
        if(isQueueEmpty()){
            createGenesisNode(val);
            //printQueue();
            return;
        }       

        Node* t = new Node(val);

        // attach t
        b -> next = t;
        t -> prev = b;

        // update b
        b = t;

        // update middle 
        if(size % 2 == 0){
            m = m -> next;
        }

        // update size
        size++;

        //printQueue();
    }
    
    int popFront() {
        if(isQueueEmpty()){
            //printQueue();
            return -1;
        }
        
        int res = f -> val;
        
        if(size == 1){
            m = m -> next;
            b = b -> next;
        }
        // isolate f
        Node* t = f;

        // update f
        f = f -> next;
        if(f){
            f -> prev = nullptr;
        }

        // update m
        if(m && size % 2 == 0){
            m = m -> next;
        }
        
        // cutoff t
        t -> prev = nullptr;            //remove
        t -> next = nullptr;

        // update size
        size--;

        //printQueue();
        return res;
    }
    
    int popMiddle() {
        if(isQueueEmpty()){
            //printQueue();
            return -1;
        }

        int res = m -> val;

        // isolate m
        Node* t = m;

        // update m
        if(size == 1){
            m = m -> prev;

            f = f -> prev;
            b = b -> prev;
        }
        else if(size == 2){
            m = m -> next;

            f = f -> next;
            f -> prev = nullptr;
        }

        if(size > 2 && size % 2){
            m = m -> prev;

            m -> next = t -> next;
            (t -> next) -> prev = m;
        }
        else if(size > 2){
            m = m -> next;

            m -> prev = t -> prev;
            (t -> prev) -> next = m;
        }

        // cutoff t
        t -> prev = nullptr;
        t -> next = nullptr;
        
        // update size
        size--;

        //printQueue();
        return res;
    }
    
    int popBack() {
        if(isQueueEmpty()){
            //printQueue();
            return -1;
        }
        // grab val
        int res = b -> val;

        // handle edge case
        if(size == 1){
            f = f -> prev;
            m = m -> prev;
        }

        // isolate b
        Node* t = b;

        // update b
        b = b -> prev;
        if(b){
            b -> next = nullptr;
        }

        // cutoff t                 // move after update m?
        t -> prev = nullptr;
        t -> next = nullptr;            //remove?

        // update m 
        if(m && size % 2){
            m = m -> prev;
        }

        // update size
        size--;

        //printQueue();
        return res;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */