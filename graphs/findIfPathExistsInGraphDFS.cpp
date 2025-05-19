class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, int current, int destination){
        if(current == destination){
            return true;
        }
        visited[current] = true;
        for(int neighbor: graph[current]){
            if(!visited[neighbor] && dfs(graph, visited, neighbor, destination)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited(n);
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        } 
        return dfs(graph, visited, source, destination); 
    }
};