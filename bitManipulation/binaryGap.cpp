class Solution {
public:
    int find_start_ind(int n){
        for(int i = 0; i < 32; i++){
            uint32_t mask = 0x80000000 >> i;
            if(n & mask){
                return i;
            }
        }
        return 32;
    }
    
    int binaryGap(int n) {
        int starting_ind = find_start_ind(n);
        int res = 0;
        int cur = 0;
        for(int i = starting_ind; i < 32; i++){
            uint32_t bitmask = 0x80000000 >> i;
            if(n & bitmask){
                res = max(res, cur);
                cur = 1;
            }
            else{
                cur++;
            }
        }
        return res;
    }
};