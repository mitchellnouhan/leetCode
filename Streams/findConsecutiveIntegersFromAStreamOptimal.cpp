class DataStream {
public:
    int count = 0;
    int value;
    int k;

    DataStream(int value, int k) {
        this -> value = value;
        this -> k = k;
    }
    
    bool consec(int num) {
        this -> count = (num == this -> value) ? this -> count + 1 : 0;
        return (this -> count >= this -> k) ? true : false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */