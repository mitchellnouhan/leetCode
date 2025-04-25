class Solution {
public:
    int smallestNumber(int n) {
        /*
        -iterate thru n's bits from left to right (ms to ls) until you hit the first set bit
        -set the remaining bits true following the first set bit
        */
        int res = 0;
        bool flag = false;
        for(int i = 0; i < 32; i++){
            int mask = 0x80000000 >> i;
            if((n & mask) || flag){
                flag = true;
                res |= mask;
            }
        }
        return res;
    }
};

/*
n = 5
101 -> 111 

n = 10
1010
1111

n = 3
11
11

*/