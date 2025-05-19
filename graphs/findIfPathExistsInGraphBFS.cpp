class Solution {
public:
    bool bfs(unordered_map<int, vector<int>>& graph, unordered_map<int, bool>& visited, queue<int>& q, int destination){
        while(q.size()){
            int current = q.front();
            q.pop();

            if(current == destination){
                return true;
            }
            for(int nei: graph[current]){
                if(!visited[nei]){
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, bool> visited(n);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }


        return bfs(graph, visited, q, destination);
    }
};