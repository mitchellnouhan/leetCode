class ProductOfNumbers {
public:
    vector<int> stream;

    ProductOfNumbers() {  
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int res = 1;
        int end = stream.size() - 1;
        for(int i = 0; i < k; i++){
            res *= stream[end - i];
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */