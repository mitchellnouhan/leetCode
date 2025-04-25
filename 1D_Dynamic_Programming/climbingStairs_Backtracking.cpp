class Solution {
public:
    int climbStairs(int n) {
        return (n < 2) ? 1 : climbStairs(n - 1) + climbStairs(n - 2); 
    }
};
