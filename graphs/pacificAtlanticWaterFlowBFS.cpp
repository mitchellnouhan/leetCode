class Solution {
public:
    void readyQueues(vector<vector<int>>& heights, int rows, int cols, queue<pair<int, int>>& pac_q, queue<pair<int, int>>& atl_q, vector<vector<bool>>& pac_v, vector<vector<bool>>& atl_v, vector<vector<bool>>& pac_r, vector<vector<bool>>& atl_r){
        //top and bottom rows
        int pac_row = 0;
        int atl_row = rows - 1;
        for(int c = 0; c < cols; c++){
            pac_v[pac_row][c] = true;
            pac_r[pac_row][c] = true;
            pac_q.push({pac_row, c});
            atl_v[atl_row][c] = true;
            atl_r[atl_row][c] = true;
            atl_q.push({atl_row, c});
        }

        //left and right most cols
        int pac_col = 0;
        int atl_col = cols - 1;
        for(int r = 0; r < rows; r++){
            pac_v[r][pac_col] = true;
            pac_r[r][pac_col] = true;
            pac_q.push({r, pac_col});
            atl_v[r][atl_col] = true;
            atl_r[r][atl_col] = true;
            atl_q.push({r, atl_col});
        }
    }

    bool isValid(vector<vector<int>>& heights, int rows, int cols, int r, int c, int prev, vector<vector<bool>>& visited){
        //if neighbor is in bounds, not visited, and equal to or greater than previous val
        bool rowInBounds = 0 <= r && r < rows;
        bool colInBounds = 0 <= c && c < cols;
        bool inBounds = rowInBounds && colInBounds;
        return inBounds && !visited[r][c] && (heights[r][c] >= prev);
    }

    void bfs(vector<vector<int>>& heights, int rows, int cols, queue<pair<int, int>>& q, vector<vector<bool>>& v, vector<vector<bool>>& r){
        // since q is ready
        vector<pair<int, int>> directions ={
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        while(q.size()){
            //pop elem from queue
            pair<int, int> cur = q.front();
            q.pop();

            //for each neighbor, if it's valid
            for(pair<int, int> dir: directions){
                int r_n = cur.first + dir.first;
                int c_n = cur.second + dir.second;
                if(isValid(heights, rows, cols, r_n, c_n, heights[cur.first][cur.second], v)){
                    //add to visited
                    v[r_n][c_n] = true;
                    //add to reached
                    r[r_n][c_n] = true;
                    //push into queue
                    q.push({r_n, c_n});
                }
            }
        }
    }

    void traverseVisited(vector<vector<int>>& res, int rows, int cols, vector<vector<bool>>& pac_r, vector<vector<bool>>& atl_r){
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pac_r[r][c] && atl_r[r][c]){
                    res.push_back({r, c});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
        the trick is to do two main graph traversals
        - determine which blocks can be reached by the pacific ocean
        - determine which blocks can be reached by the atlantic ocean 
        - iterate thru both atlantic and pacific grids
            -those grid points that can be reached by both atl and pac are the res
        let's do a bfs approach
        */
        int rows = heights.size();
        int cols = heights[0].size();
        queue<pair<int, int>> pac_q;
        queue<pair<int, int>> atl_q;

        vector<bool> a_row(cols, false);
        vector<vector<bool>> pac_v(rows, a_row); 
        vector<vector<bool>> atl_v(rows, a_row);

        vector<vector<bool>> pac_r(rows, a_row); 
        vector<vector<bool>> atl_r(rows, a_row);

        //ready queue for Pacific and atlantic
            //one col number iteration for top and bottom rows
            //one row number iteration for left and right most cols
        readyQueues(heights, rows, cols, pac_q, atl_q, pac_v, atl_v, pac_r, atl_r);


        //bfs pacific
        bfs(heights, rows, cols, pac_q, pac_v, pac_r);
        
        //bfs atlantic
        bfs(heights, rows, cols, atl_q, atl_v, atl_r);

        //traverse pacific and atlantic reached grids
        vector<vector<int>> res;
        traverseVisited(res, rows, cols, pac_r, atl_r);
        
        //return result
        return res;
    }
};
