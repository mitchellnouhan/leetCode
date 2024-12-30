class Solution {
public:
    bool isValid(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        int rows = grid.size();
        int cols = grid[0].size();

        bool rowInBounds = 0 <= r && r < rows;
        bool colInBounds = 0 <= c && c < cols;
        bool inBounds = rowInBounds && colInBounds;
        int ISLAND = 2147483647;
        //for each neighbor, if it's valid, modify grid
        // valid: if it's inbounds, unvisited, and an island
        return inBounds && !visited[r][c] && grid[r][c] == ISLAND;
    }
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q){
        int dist = 0;
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        while(q.size()){
            dist++;
            //for(pair<int, int> elem: q){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                pair<int, int> cur = q.front();
                q.pop();
                for(pair<int, int> dir: directions){
                    int r_n = cur.first + dir.first;
                    int c_n = cur.second + dir.second;
                    if(isValid(r_n, c_n, grid, visited)){
                        grid[r_n][c_n] = dist;
                        visited[r_n][c_n] = true;
                        q.push({r_n, c_n});
                    }
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        /*
        as neetcode and euler said, INVERT!
        do a BFS from the Treasures' perspectives
        do a BFS from the treasure points simultaneously
        check the neighbors, if not visited, in bounds, and is an island
            modify the grid value to the current distance value
        
        1. iterate thru grid, enqueue the treasure points
        2. run bfs w/ our treasure ready queue
        3. return grid 
        */
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bool> a_row(cols, false);
        vector<vector<bool>> visited(rows, a_row);
        queue<pair<int, int>> q;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0){
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        bfs(grid, visited, q);
    }
};
