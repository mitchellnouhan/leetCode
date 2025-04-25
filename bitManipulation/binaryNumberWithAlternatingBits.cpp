class Solution {
public:
    int grab_start_ind(int n){
        for(int i = 0; i < 32; i++){
            if(n & (0x80000000 >> i)){
                return i;
            }
        }
        return 31;
    }
    bool hasAlternatingBits(int n) {
        /*
        iterate through bits until you hit first 1
        save index
        starting from that index, look ahead
        those two bits xor'ed together should be true:) 
        */
        int start_ind = grab_start_ind(n);
        for(int i = start_ind; i < 31; i++){
            uint32_t mask_current = 0x80000000 >> i;
            uint32_t mask_ahead   = 0x80000000 >> (i + 1);
            bool cur_bit = n & mask_current;
            bool next_bit = n & mask_ahead;
            if((cur_bit ^ next_bit) == 0){
                return false;
            }
        }
        return true;  
    }
};