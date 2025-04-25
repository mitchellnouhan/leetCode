class Solution {
public:
    unordered_map<int, vector<int>> crs_graph;
    unordered_set<int> visited;
    unordered_set<int> complete;
    vector<int> res;

    bool dfs(int crs){
        // base cases
        if(crs_graph[crs].empty()){
            if(complete.count(crs) == 0){
                res.push_back(crs);
                complete.insert(crs);
            }
            return true;
        }
        if(visited.count(crs)){
            return false;
        }
        
        visited.insert(crs);
        for(int pre: crs_graph[crs]){
            if(!dfs(pre)){
                return false;
            }
        }
        visited.erase(crs);
        crs_graph[crs].clear();
        if(complete.count(crs) == 0){
            res.push_back(crs);
            complete.insert(crs);
        }
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create crs_graph from prereq list
        for(int i = 0 ; i < numCourses; i++){
            crs_graph[i] = {};
        }
        for(auto prereq: prerequisites){
            crs_graph[prereq[0]].push_back(prereq[1]);
        }

        // iterate thru n
        // call dfs on each course
        for(int i = 0; i < numCourses; i++){
            if(!dfs(i)){
                return {};
            }
        }
        return res;
    }
};
