class Solution {
public:
    unordered_map<int, int> memo = {{0,1}, {1,1}};
    int climbStairs(int n) {
        if(memo.count(n)){
            return memo[n];
        }
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }
};
