class Solution {
public:
    unordered_map<int, vector<int>> adj_list;
    unordered_set<int> visited;

    bool dfs(int cur, int pre){
        // base cases
        // if we have visited this node before, return false
        if(visited.count(cur)){
            return false;
        }

        // recursive cases
        // add node to visited set
        visited.insert(cur);
        // for each of node's neighbor (except previous node) 
        //run a dfs on it
        for(int nei: adj_list[cur]){
            if(nei == pre){
                continue;
            }
            if(!dfs(nei, cur)){
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        /*
        -general idea: dfs on the graph
        -during the dfs traversal, we will be keeping track of visited nodes
        -if we encounter a visited node during the graph traversal, we have detected a loop/cycle
        -after we traversed the graph, we want to make sure all nodes of the graph are connected
        by checking the length of our visited set with our graph DS
        */
        
        // create adj_list
        for(int i = 0; i < n; i++){
            adj_list[i] = {};
        }
        for(auto edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // traverse tree and check for no cycles
        bool no_cycles = dfs(0, -1);

        // check if all nodes in the graph are connected
        bool connected = visited.size() == n;

        // return if the graph has no cycles and is connected
        return no_cycles && connected;
    }
};
