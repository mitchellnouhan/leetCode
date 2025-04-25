class Solution {
public:
    unordered_map<int, vector<int>> adj_list;
    vector<vector<int>> res;
    unordered_set<int> visited;
    void dfs(int node){
        if(visited.count(node)){
            return;
        }
        
        visited.insert(node);
        for(int nei: adj_list[node]){
            dfs(nei);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        //create adjacency list
        for(int i = 0; i < n; i++){
            adj_list[i] = {};
        }
        for(auto edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        //dfs on each of the nodes
        for(int i = 0; i < n; i++){
            if(visited.count(i) == 0){
                res++;
                dfs(i);
            }
        }
        return res;
    }
};
