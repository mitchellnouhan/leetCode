class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int x_or = x ^ y;
        for(int i = 0; i < 32; i++){
            uint32_t bitmask = (0x80000000 >> i);
            if(bitmask & x_or){
                res++;
            }
        }
        return res;
    }
};