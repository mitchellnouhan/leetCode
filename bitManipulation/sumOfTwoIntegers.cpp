class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int carry = 0;
        int mask = 0x00000001;

        for(int i = 0; i < 32; i++){
            int a_bit = a & mask;
            int b_bit = b & mask;

            res |= a_bit ^ b_bit ^ carry;
            carry = ((a_bit & b_bit) | (carry & (a_bit | b_bit))) << (1);
            
            mask <<= 1; 
        }
        
        return res;
    }
};
