class FirstUnique {
public:
    queue<int> stream;
    unordered_map<int, int> freq;

    FirstUnique(vector<int>& nums) {     
        for(int num: nums){
            add_to_stream(num);
        }
        cleanup_stream();   
    }
    
    int showFirstUnique() {
        return stream.size() ? stream.front() : -1;
    }
    
    void add_to_stream(int val){
        freq[val]++;
        if(freq[val] == 1){
            stream.push(val);
        }
    }

    void cleanup_stream(){
        while(stream.size() && freq[stream.front()] > 1){
            stream.pop();
        }
    }

    void add(int value) {
        add_to_stream(value);
        cleanup_stream();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */