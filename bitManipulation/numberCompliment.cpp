class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int i = 0;
        uint32_t bitmask = 0x80000000;
        while((num & (bitmask >> i)) == 0){
            i++;
        }
        for(int j = i; j < 32; j++){
            if((num & (bitmask >> j)) == 0){
                res |= (bitmask >> j);
            }
        }
        return res;
    }
};