class Solution {
public:
    int countBits(int num){
        int res = 0;
        for(int i = 0; i < 32; i++){
            int mask = 1 << i;
            if(mask & num){
                res++;
            }
        }
        return res;
    }

    int minBitFlips(int start, int goal) {
        return countBits(start ^ goal);
    }
};