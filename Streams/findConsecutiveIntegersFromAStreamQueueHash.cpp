class DataStream {
public:
    unordered_map<int, int> freq;
    queue<int> q;
    int V;
    int K;


    DataStream(int value, int k) {
        V = value;
        K = k;
    }
    
    bool consec(int num) {
        //always going to push back
        q.push(num);
        if(freq.count(num) == 0){
            freq[num] = 1;
        }
        else{
            freq[num]++;
        }

        //check if we have to pop front
        if(q.size() > K){
            freq[ q.front() ]--;
            q.pop();
        }
        
        //check hash
        return freq[V] == K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */