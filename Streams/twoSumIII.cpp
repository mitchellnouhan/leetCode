class TwoSum {
public:

    unordered_map<int, int> freq;

    TwoSum() {
    }
    
    void add(int number) {
        freq[number]++;
    }
    
    bool find(int value) {
        for(auto num_freq: freq){
            long look = (long)value - (long)num_freq.first;
            if((look != num_freq.first && freq.count(look)) || (look == num_freq.first && num_freq.second > 1)){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */