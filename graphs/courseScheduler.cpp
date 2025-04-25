class Solution {
public:
    unordered_map<int, vector<int>> graph;
    unordered_set<int> visited;
    bool dfs(int crs){
        // base case(s)
        // if the crs prereq vector is empty, return true
        if (graph[crs].empty()){
            return true;
        }
        // if we have visited the crs before, we are in a loop!, return false
        if(visited.count(crs)){
            return false;
        }
        
        // recursive case(s)
        visited.insert(crs);
        // for each prereq of crs, see if we can complete it
        for(int pre: graph[crs]){
            if(!dfs(pre)){
                return false;
            }
        }
        visited.erase(crs);
        graph[crs].clear();
        return true;
        // add prereq to visited
        // if not return false
        // if so, remove prereq from visited set && remove prereq from crs's prereq vector
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create a graph DS using an adjacency list
        // we want to iterate through each course (could be unconnected parts of the graph)
        //and check if we can complete each course
        // we will check if we can complete each course with dfs

        for(int crs = 0; crs < numCourses; crs++){
            graph[crs] = {};
        }

        for(auto prereq_pair: prerequisites){
            int crs = prereq_pair[0];
            int pre = prereq_pair[1];

            graph[crs].push_back(pre);
        }

        for(int crs = 0; crs < numCourses; crs++){
            if(!dfs(crs)){
                return false;
            }
        }
        return true;
    }
};
