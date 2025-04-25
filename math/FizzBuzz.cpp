class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for(int i = 0; i < n; i++){
            int ind = i + 1;
            if((ind % 3 == 0) && (ind % 5 == 0)){
                res[i] = "FizzBuzz";
            }
            else if(ind % 3 == 0){
                res[i] = "Fizz";
            }
            else if(ind % 5 == 0){
                res[i] = "Buzz";
            }
            else{
                res[i] = to_string(ind);
            }
        }
        return res;
    }
};