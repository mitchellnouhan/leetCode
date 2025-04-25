class KthLargest {
public:
    priority_queue<int> min_heap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int i = 0; i < nums.size(); i++){
            if(i < this -> k){
                min_heap.push(-1 * nums[i]);
            }
            else if(-1 * nums[i] < min_heap.top()){
                min_heap.pop();
                min_heap.push(-1 * nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(min_heap.size() < this -> k){
            min_heap.push(-1 * val);
        }
        else if(-1 * val < min_heap.top()){
            min_heap.pop();
            min_heap.push(-1 * val);
        }
        return -1 * min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */