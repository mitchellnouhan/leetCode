class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int inputSizeBits = 32;
        uint32_t bitMask = 1;
        for (int i = 0; i < inputSizeBits; i++){
            //push res to the left
            res <<= 1;

            //grab bit and assign res the bit
            res |= (n & bitMask) >> i;

            //update bitMask
            bitMask <<= 1;
        }
        return res;
    }
};