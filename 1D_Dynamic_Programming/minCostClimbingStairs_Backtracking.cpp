class Solution {
public:
    int bt_dfs(vector<int>& cost, int i){
        return (i >= cost.size()) ? 0 : cost[i] + min(bt_dfs(cost, i + 1), bt_dfs(cost, i + 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(bt_dfs(cost, 0), bt_dfs(cost, 1));
    }
};
