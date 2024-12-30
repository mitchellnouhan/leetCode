class Solution {
public:
    bool checkForFreshFruit(vector<vector<int>>& grid, int rows, int cols){
        bool res = false;
        int FRESH = 1;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == FRESH){
                    return true;
                }
            }
        }
        return res;
    }
    bool isValid(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int rows, int cols){
        //inbounds, hasn't been visited, is fresh fruit
        int FRESH = 1;
        bool rowInBounds = 0 <= r && r < rows;
        bool colInBounds = 0 <= c && c < cols;
        bool inBounds = rowInBounds && colInBounds;
        return inBounds && !visited[r][c] && grid[r][c] == FRESH;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int rows, int cols){
        //we need our grid, our visited, q, rows, cols
        int time = -1;


        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        while(q.size()){
            time++;
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                pair<int, int> cur = q.front();
                q.pop();
                for(pair<int, int> dir: directions){
                    int r_n = cur.first + dir.first;
                    int c_n = cur.second + dir.second;
                    if(isValid(grid, visited, r_n, c_n, rows, cols)){
                        grid[r_n][c_n] = 2;
                        visited[r_n][c_n] = true;
                        q.push({r_n, c_n});
                    }
                }
            }
        }

        return time;
    }

    void grabRottenFruit(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int rows, int cols){ 
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2){
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        /*
        we want to do a BFS from the perspective of the rotten fruit
        start up the queue with the rotten fruit
        then do a BFS from the rotten fruit to the fresh fruit
        every iteration of the BFS, we increment our timer
        if timer == 1, return -1
        else return timer - 1;
        1.get queue ready for BFS with rotten fruit
        2.do a BFS
            -maybe have a helper function
        3. return res of BFS
        */
        int rows = grid.size();
        int cols = grid[0].size();

        vector<bool> a_row(cols, false); 
        vector<vector<bool>> visited(rows, a_row);

        queue<pair<int, int>> q;

        grabRottenFruit(grid, visited, q, rows, cols);
        int res = bfs(grid, visited, q, rows, cols);
        if(checkForFreshFruit(grid, rows, cols))
            return -1;
        else if(res == -1)
            return 0;
        return res;
    }
};
