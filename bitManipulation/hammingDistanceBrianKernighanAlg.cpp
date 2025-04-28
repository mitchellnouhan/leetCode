class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        int x_or = x ^ y;
        while(x_or){
            res++;
            x_or = x_or & (x_or - 1);
        }
        return res;
    }
};