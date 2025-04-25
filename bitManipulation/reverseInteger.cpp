class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x){
            int dig = (x % 10);
            //overflow
            if(res > 214748364 || (res == 214748364 && dig > 7))
                return 0;
            //underflow
            if(res < -214748364 || (res == -214748364 && dig < -8))
                return 0;
            res *= 10;
            res += dig;
            x /= 10;
        }
        return res;
    }
};
