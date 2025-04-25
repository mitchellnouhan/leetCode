class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        int hash[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
        for(int i = left; i <= right; i++){
            bitset<20> b(i);
            if(hash[b.count()]){
                res++;
            }
        }
        return res;
    }
};