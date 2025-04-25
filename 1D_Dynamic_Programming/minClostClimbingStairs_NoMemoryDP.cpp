class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i = 2;
        int index = cost.size() - 1;
        int dp1 = 0;
        int dp2 = 0;

        while(index >= 0){
            int tmp = dp1;
            dp1 = cost[index] + min(dp1, dp2);
            dp2 = tmp;
            i++;
            index--;
        }
        return min(dp1, dp2);
    }
};
