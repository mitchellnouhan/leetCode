class Solution {
public:
    unordered_map<int, int> stair_to_min_cost;
    int bt_dfs(vector<int>& cost, int i){
        if(stair_to_min_cost.count(i)){
            return stair_to_min_cost[i];
        }
        stair_to_min_cost[i] = cost[i] + min(bt_dfs(cost, i + 1), bt_dfs(cost, i + 2));
        return stair_to_min_cost[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        stair_to_min_cost[cost.size()] = 0;
        stair_to_min_cost[cost.size() + 1] = 0;
        return min(bt_dfs(cost, 0), bt_dfs(cost, 1));
    }
};
