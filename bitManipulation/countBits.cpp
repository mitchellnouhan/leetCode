class Solution {
public:
    int hammingBits(int n){
        int res = 0;
        int inputSizeBits = 32;
        uint32_t bitMask = 1;
        for (int i = 0; i < inputSizeBits; i++){
            if(n & bitMask){
                res++;
            }
            bitMask <<= 1;
        }
        return res;
    }
    vector<int> countBits(int n) {   
        int initVal = 0;
        vector<int> res(n + 1, initVal);
        for (int i = 0; i <= n; i++){
            res[i] = Solution::hammingBits(i);
        }
        return res;
    }
};