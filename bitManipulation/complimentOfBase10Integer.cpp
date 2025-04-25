class Solution {
public:
    int startingBit(int num){
        for(int i = 0; i < 32; i++){
            uint32_t mask = 0x80000000 >> i;
            if(num & mask){
                return i;
            }
        }
        return 32;
    }
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }
        
        int res = 0;
        int startingInd = startingBit(n);
        for(int i = startingInd; i < 32; i++){
            uint32_t mask = 0x80000000 >> i;
            res |= (mask ^ (n & mask));
        }
        return res;
    }
};