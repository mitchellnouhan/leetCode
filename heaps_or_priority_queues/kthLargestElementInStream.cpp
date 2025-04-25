class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int num: nums)
            min_heap.push(num);

        while(min_heap.size() > this -> k)
            min_heap.pop();
    }
    
    int add(int val) {
        min_heap.push(val);
        while(min_heap.size() > k)
            min_heap.pop();
        return min_heap.top();
    }
};
