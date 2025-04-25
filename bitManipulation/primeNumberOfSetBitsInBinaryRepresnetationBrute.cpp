class Solution {
public:

    unordered_map<int, bool> prime = {
        {1, false},
    };

    bool isPrime(int num){
        //starting from 2 all the say 
        //only divisible by 1 and itself
        if(prime.count(num)){
            return prime[num];
        }
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                prime[num] = false;
                return prime[num];
            }
        }
        prime[num] = true;
        return prime[num];
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