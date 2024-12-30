class Solution {
public:
    int bfs(vector<vector<int>> grid, vector<vector<bool>> visited, int r, int c){
        /*
        we need a queue DS
        -update visited
        -inc area by one
        -enqueue
        while the queue isnt empty
            -dequeue
            -for each of the elem's neighbors
                -if land, in bounds and unvisited
                    -update visisted
                    -inc area by one 
                    -enqueue
        
        */
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        visited[r][c] = true;
        res++;
        q.push({r, c});
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1},
        };
        while(q.size()){
            pair<int, int> cur_elem = q.front();
            q.pop();
            for(pair<int, int> dir: directions){
                // r_n: row neighbor, c_n: col neighbor, n: neighbor
                int r_n = cur_elem.first + dir.first;
                int c_n = cur_elem.second + dir.second;

                bool row_in_bounds = 0 <= r_n && r_n < rows;
                bool col_in_bounds = 0 <= c_n && c_n < cols;
                bool in_bounds = row_in_bounds && col_in_bounds;
                if(in_bounds && grid[r_n][c_n] && !visited[r_n][c_n]){
                    //update visit
                    visited[r_n][c_n] = true;
                    //update area
                    res++;
                    //enqueue neighbor
                    q.push({r_n, c_n});
                }
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        /*
        we are going to iterate thru the grid   
        if we stumble upon unvisited land, then we know this 
        is an island
        we can conduct either a breadth first search or a 
        depth first search w/ a return value of the island area        
        */
        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bool> a_row(cols, false);
        vector<vector<bool>> visited(rows, a_row);
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] and !visited[r][c]){
                    int cur_area = bfs(grid, visited, r, c);
                    res = max(res, cur_area);
                }
            }
        }
        return res;
    }
};
