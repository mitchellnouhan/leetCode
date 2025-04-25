class Solution {
public:
    int climbStairs(int n) {
        int stairOne = 1;
        int stairTwo = 0;
        int i = 1;
        while(i < n){
            int tmp = stairOne;
            stairOne = stairOne + stairTwo;
            stairTwo = tmp;
            i++;
        }
        return stairOne + stairTwo;
    }
};
