class Solution {
public:
    bool isPrime(int num){
        return (num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17 || num == 19) ? true : false;
    }
    
    int countSetBits(int num){
        int res = 0;
        for(int i = 0; i < 32; i++){
            uint32_t mask = 0x80000000 >> i;
            if(num & mask){
                res++;
            }
        }
        return res;
    }

    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++){
            if(isPrime(countSetBits(i))){
                res++;
            }
        }
        return res;
    }
};