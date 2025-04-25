class Solution {
public:
    int minChanges(int n, int k) {
        /*
        n: 1 -> 0
        go thru bit by bit of n and k
        if n == 1 and k == 0
            inc res
        if n == 0 and k == 1
            return -1

        n = 13
        k = 4
        1101
        0100
        n = 14
        k = 13
        1110
        1101
        */
        int res = 0;
        for(int i = 0; i < 32; i++){
            int mask = 0x80000000 >> i;
            int n_bit = n & mask;
            int k_bit = k & mask;
            if(n_bit && !k_bit){
                res++;
            }
            else if(!n_bit && k_bit){
                return -1;
            }
        }
        return res;
    }
};