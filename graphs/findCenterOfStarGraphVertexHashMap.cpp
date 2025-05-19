class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            if(graph[u].size() > 1){
                return u;
            }
            if(graph[v].size() > 1){
                return v;
            }
        }
        return -1;
    }
};