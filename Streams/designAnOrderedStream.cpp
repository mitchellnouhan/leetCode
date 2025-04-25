class OrderedStream {
public:
    vector<string> s;
    int p;

    OrderedStream(int n) {
        p = 0;
        for(int i = 0; i < n; i++){
            s.push_back("");
        }
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res = {};
        s[idKey - 1] = value;
        while(p < s.size() && s[p] != ""){
            res.push_back(s[p]);
            p++;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */