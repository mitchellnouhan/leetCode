class Solution {
public:
    bool dfs_iterative(unordered_map<int, vector<int>>& graph, vector<bool>& visited, deque<int>& q, int destination){
        while(q.size()){
            
            int current = q.back();
            q.pop_back();
            if(current == destination){
                return true;
            }
            for(int nei: graph[current]){
                if(!visited[nei]){
                    visited[nei] = true;
                    q.push_back(nei);
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        vector<bool> visited(n, false);
        deque<int> q;

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        visited[source] = true;
        q.push_back(source);

        return dfs_iterative(graph, visited, q, destination);
    }
};