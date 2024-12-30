class Node {
//
public:
    //
    Node* p;
    Node* n;
    int k;
    int v;
    Node(int key, int value, Node* prev, Node* next){
        p = nullptr;
        n = nullptr;
        k = key;
        v = value;
    }
};

class LRUCache {
public:
    //we need a head & tail pointers 
    Node* h;
    Node* t;
    //LRU capacity var
    int cap;
    //LRU cur size
    int cur_size;

    //hashtable to grab Node addresses based on key
    unordered_map< int, Node* > hash;

    LRUCache(int capacity) {
        // assign capacity and init cur_size
        cap = capacity;
        cur_size = 0;

        //create an empty node to assign head and tail to
        //h = new Node(-1,-1,nullptr,nullptr);
        h = nullptr;
        t = h;
    }
    
    void moveNodeToHead(Node* cur){
        // take key, value Node and put it at the head of LL
        // if cur is head, nothing to do
        if (cur == h){
            return;
        }

        //if this is the first Node in LL, just ass
        if(h == nullptr && t == nullptr){
            h = cur;
            t = cur;
            return;
        }

        // if cur isn't head
        //take care of neighbors pointers
        if (cur -> p){
            cur -> p -> n = cur -> n;
        }
        if (cur -> n){
            cur -> n -> p = cur -> p;
        }

        //take care of cur's points while updating t accordingly
        cur -> n = h;
        if (cur == t){
            t = t -> p;
        }
        cur -> p = nullptr;

        //update h
        if(h){
            h -> p = cur;
        }
        h = cur;
    }

    int get(int key) {
        // if it doesn't exist, return -1
        if(!hash[key])
            return -1;
        
        // if it does exist, we want to move LL val to front of the LL
        moveNodeToHead(hash[key]);
        // then return value
        return hash[key] -> v;
    }
    
    void put(int key, int value) {
        // if it doesn't exist, create new node & update hashtable
        Node* cur;
        if (!hash[key]){
            cur = new Node(key, value, nullptr, nullptr);
            cur_size++;
            hash[key] = cur;
        }
        else{
            cur = hash[key];
            cur -> v = value;
        }
        
        //put cur at front of list
        moveNodeToHead(cur);


        // if size is greater than cap, evict tail:)
        if(cur_size <= cap){
            return;
        }

        //update size
        cur_size--;

        //update hash table
        hash[t -> k] = nullptr;

        //update tail to prev value and delete old tail
        Node* tmp = t;
        t = t -> p;
        t -> n = nullptr;

        tmp -> p = nullptr;
        //free(tmp);
        delete tmp;
    }
};
