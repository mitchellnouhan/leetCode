class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        uint32_t input = n;
        uint32_t mask = 0x00000001;
        for (int i = 0; i < 32; i++){
            if(input & mask)
                res++;
            input >>= 1;
        }
        return res;
    }
};
