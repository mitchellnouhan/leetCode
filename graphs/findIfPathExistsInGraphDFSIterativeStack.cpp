class Solution {
public:
    bool dfs_iterative(unordered_map<int, vector<int>>& graph, vector<bool>& visited, stack<int>& s, int destination){
        while(s.size()){
            int current = s.top();
            s.pop();

            if(current == destination){
                return true;
            }
            for(int nei: graph[current]){
                if(!visited[nei]){
                    visited[nei] = true;
                    s.push(nei);
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, false);
        stack<int> s;

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        s.push(source);
        visited[source] = true;

        return dfs_iterative(graph, visited, s, destination);
    }
};