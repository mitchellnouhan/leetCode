class ProductOfNumbers {
public:
    vector<int> stream;
    vector<int> prefix;
    int n;

    ProductOfNumbers() {
        n = 0;
    }
    
    void add(int num) {
        stream.push_back(num);
        if(num == 0){
            stream.clear();
            prefix.clear();
            n = 0;
            return;
        }

        if(n == 0){
            prefix.push_back(1);
        }
        else{
            prefix.push_back(stream[n - 1] * prefix[n - 1]);
        }
        n++;
    }
    
    int getProduct(int k) {
        if(k > n){
            return 0;
        }
        int end = n - 1;
        return (stream[end] * prefix[end]) / prefix[end - k + 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);

3
1

3,1
1,3

3,1,2
1,3,3

3,1,2,5
1,3,3,6

3,1,2,5,4
1,3,3,6,30

3
1

3,0
1,0

3,0,2
_,_,1

3,0,2,5
_,_,1,2

3,0,2,5,4
_,_,1,2,10

num[n] * pre[n] / pre[n - k + 1]

 */