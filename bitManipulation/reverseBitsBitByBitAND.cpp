class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            uint32_t bit_mask = 0x80000000 >> i;
            res |= (bool)(bit_mask & n) << i;
        }
        return res;
    }
};