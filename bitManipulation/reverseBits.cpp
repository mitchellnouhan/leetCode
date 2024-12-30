class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //push res to the left
        //grab the lsb
        //or it to the res
        
        uint32_t res = 0;
        uint32_t input = n;
        uint32_t mask = 0x00000001;
        for(int i = 0; i < 32; i++){
            res <<= 1;
            res |= (mask & input);
            input >>= 1;
        }
        return res;
    }
};
