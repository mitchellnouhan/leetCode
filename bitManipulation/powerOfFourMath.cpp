class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && (log2(n) == ceil(log2(n))) && ((((int)ceil(log2(n))) % 2) == 0);
    }
};