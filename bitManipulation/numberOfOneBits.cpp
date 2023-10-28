class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int inputBitSize = 32;
        uint32_t bitMask = 1; 
        for (int i = 0; i < inputBitSize; i++){
            if (bitMask & n){
                res++;
            }
            bitMask <<= 1;
        }
        return res;
    }
};