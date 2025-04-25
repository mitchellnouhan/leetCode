class Solution {
public:
    unordered_map<int, vector<int>> adj_list;
    
    bool dfs(int pre, int cur, unordered_set<int>& visited){
        if(visited.count(cur)){
            return false;
        }

        visited.insert(cur);
        for(int nei: adj_list[cur]){
            if(nei != pre && !dfs(cur, nei, visited)){
                return false;
            }
        }
        visited.erase(cur);
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> visited;
        for(auto const edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
            if(!dfs(0, edge[0], visited)){
                return {edge[0], edge[1]};
            }
        }
        return {};
    }
};
