class Solution {
public:
    void printVisited(vector<vector<bool>>& visited){
        for(int i = 0; i < visited.size(); i++){
            for(int j = 0; j < visited[0].size(); j++){
                cout << visited[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void bfs(vector<vector<char>> grid, vector<vector<bool>>& visited, int r, int c){
        /*
        searching each layer at a given traversal tree level; looking ath the next
        layer once the current on is searched throuh
        if we are doing a bfs on a current grid elem:
        -mark it visited
        -add it to the end of our queue
        -grab the next elem to traverse from the queue
        -for each of the four directions we can go, traverse into
        - that grid elem
        
        */
        vector<pair<int, int>> neighbors = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        //queue<pair<int, int>> q;
        deque<pair<int, int>> q;
        
        visited[r][c] = true;
        printVisited(visited);
        //q.push({r, c});
        q.push_back({r, c});
        int rows = grid.size();
        int cols = grid[0].size();

        while (q.size()){
            //four directions are up, down, left, right:
            //(r + 1, c)
            //(r - 1, c)
            //(r, c - 1)
            //(r, c + 1)


            //pair<int, int> grid_elem = q.front();
            //q.pop();
            pair<int, int> grid_elem = q.back();
            q.pop_back();

            for(auto neighbor: neighbors){
                int r_n = grid_elem.first + neighbor.first;
                int c_n = grid_elem.second + neighbor.second;
                bool row_inbounds = (0 <= r_n && r_n <= rows - 1);
                bool col_inbounds = (0 <= c_n && c_n <= cols - 1);
                bool inbounds = row_inbounds && col_inbounds;
                //bool land = ();

                if((inbounds) && (grid[r_n][c_n] == '1') && (!visited[r_n][c_n])){
                    visited[r_n][c_n] = true;
                    printVisited(visited);
                    //q.push({r_n, c_n});
                    q.push_back({r_n, c_n});
                }

            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        /*
        we are going to traverse thru each elem on the grid;
        if we encounter an unvisited piece of land, we want to run
        a breadth first search on that piece of land. 
        */

        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        printVisited(visited);
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if ((grid[r][c] == '1') && (!visited[r][c])){
                    res++;
                    bfs(grid, visited, r, c);
                    //printVisited(visited);
                    //visited[r][c] = true;
                }
            }
        }
        return res;
    }
};
