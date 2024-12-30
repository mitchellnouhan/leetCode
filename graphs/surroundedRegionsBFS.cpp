class Solution {
    int rows;
    int cols;
    vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };
private:
    void readyQueue(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<bool>>& parimeter_groups, queue<pair<int, int>>& q){
        //check top and bottom rows of board
        int r_t = 0;
        int r_b = rows - 1;
        for(int c = 0; c < cols; c++){
            if(board[r_t][c] == 'O'){
                visited[r_t][c] = true;
                parimeter_groups[r_t][c] = true;
                q.push({r_t, c});
            }
            if (board[r_b][c] == 'O'){
                visited[r_b][c] = true;
                parimeter_groups[r_b][c] = true;
                q.push({r_b, c});
            }
        }
        //check left and right most rows of the board
        int c_l = 0;
        int c_r = cols - 1;
        for(int r = 0; r < rows; r++){
            if(board[r][c_l] == 'O'){
                visited[r][c_l] = true;
                parimeter_groups[r][c_l] = true;
                q.push({r, c_l});
            }
            if (board[r][c_r] == 'O'){
                visited[r][c_r] = true;
                parimeter_groups[r][c_r] = true;
                q.push({r, c_r});
            }  
        }
    }

    bool isValid(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited){
        bool rowInBounds = 0 <= r && r < rows;
        bool colInBounds = 0 <= c && c < cols;
        bool inBounds = rowInBounds && colInBounds;
        return inBounds && !visited[r][c] && board[r][c] == 'O';
    }

    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<bool>>& parimeter_groups, queue<pair<int, int>>& q){
        
        while(q.size()){
            pair<int, int> cur = q.front();
            q.pop();
            //for each neighbor,
                //if neighbor is valid()
                    //valid: in bounds, unvisited, and is an O
                //add to visited
                //add to parimeter group
                //push to queue
            for(pair<int, int> dir: directions){
                int r_n = cur.first + dir.first;
                int c_n = cur.second + dir.second;
                if(isValid(r_n, c_n, board, visited)){
                    visited[r_n][c_n] = true;
                    parimeter_groups[r_n][c_n] = true;
                    q.push({r_n, c_n});
                }
            }
        }
    }

    void modifyBoard(vector<vector<char>>& board, vector<vector<bool>>& parimeter_groups){
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if (!parimeter_groups[r][c]){
                    board[r][c] = 'X';
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        /*
        -key idea(s):
        -any O around the parameter is automatically not surrounded
        -any O around the parameter can be part of a group of O's
        further in the board

        -any O's not part of a parimeter group is surrounded

        1. go around the parameter and enqueue any O's
        2. using a BFS, keep track of any other O's part of parimeter 
        groups
        3. iterate thru the board, and change any O to an X that is not part of an O parimeter group 
        */
        
        
        //ready the Queue with parameter O's
        rows = board.size();
        cols = board[0].size();

        vector<bool> a_row(cols, false);
        vector<vector<bool>> visited(rows, a_row);
        vector<vector<bool>> parimeter_groups(rows, a_row);

        queue<pair<int, int>> q;

        readyQueue(board, visited, parimeter_groups, q);

        //perform a BFS 
        bfs(board, visited, parimeter_groups, q);

        //modify board
        modifyBoard(board, parimeter_groups);
    }
};
