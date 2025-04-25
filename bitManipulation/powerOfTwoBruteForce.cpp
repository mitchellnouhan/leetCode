class Solution {
public:
    bool isPowerOfTwo(int n) {
        int exp = 0;
        while(exp < 31){
            if(n == (int)pow(2,exp)){
                return true;
            }
            exp++;
        }
        return false;
    }
};