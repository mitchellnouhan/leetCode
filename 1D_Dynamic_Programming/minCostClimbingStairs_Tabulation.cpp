class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i = 2;
        int index = cost.size() - 1;
        vector<int> costs = {0, 0};
        while(index >= 0){
            costs.push_back(cost[index] + min(costs[i - 1], costs[i - 2]));
            i++;
            index--;
        }
        return min(costs[i - 1], costs[i - 2]);
    }
};
