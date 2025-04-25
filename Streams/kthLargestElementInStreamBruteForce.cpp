class KthLargest {
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this -> k = k;
        for(int num: nums){
            stream.push_back(num);
        }
    }
    
    int add(int val) {
        stream.push_back(val);
        sort(stream.begin(), stream.end());
        return stream[stream.size() - 1 - (this -> k - 1)];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */