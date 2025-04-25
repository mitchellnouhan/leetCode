class Solution {
public:
    bool isPowerOfFour(int n) {
        int exp = 0;
        while(exp < 16){
            if(n == (int)pow(4, exp)){
                return true;
            }
            exp++;
        }
        return false;
    }
};