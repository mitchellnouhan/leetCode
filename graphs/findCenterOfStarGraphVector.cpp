class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<bool> visited(edges.size() + 1, false);
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(visited[u - 1]){
                return u;
            }
            visited[u - 1] = true;
            if(visited[v - 1]){
                return v;
            }
            visited[v - 1] = true;
        }
        return -1;
    }
};