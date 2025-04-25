class Solution {
public:
    int rows;
    int cols;
    //we need the board
    //we need a visited board
    //we need the string
    //we need the cur index

    bool isValid(vector<vector<bool>>& visited, int row, int col){
        bool rowValid = (0 <= row) && (row < this -> rows);
        bool colValid = (0 <= col) && (col < this -> cols);
        return (rowValid && colValid && !visited[row][col]) ? true : false;
    }

    bool bt(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& visited, int index, string word){
        //base cases
            //cur board letter is not cur word letter 
            //eow
        if(board[row][col] != word[index]){
            return false;
        }

        if(index == word.size() - 1){
            return true;
        }

        //recursive case
            //check it's neighbors

        //up, down, left, right
        
        visited[row][col] = true;

        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, -1},
            {0, 1}
        };

        vector<bool> direction_res = {
            false,
            false,
            false,
            false
        };

        for(int i = 0; i < direction_res.size(); i++){

            int row_n = row + directions[i].first;
            int col_n = col + directions[i].second;

            if(isValid(visited, row_n, col_n)){
                direction_res[i] = bt(board, row_n, col_n, visited, index + 1, word);
            }
        }

        bool res = false;
        for(int i = 0; i < direction_res.size(); i++){
            res |= direction_res[i];
        }

        visited[row][col] = false;      //?????
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        this -> rows = board.size();
        this -> cols = board[0].size();
        
        for(int r = 0; r < this -> rows; r++){
            for(int c = 0; c < this -> cols; c++){
                char cur = board[r][c];
                bool check = false;

                if(cur == word[0]){
                    //init visited
                    vector<bool> a_row(this -> cols, false);
                    vector<vector<bool>> visited(this -> rows, a_row);
                    visited[r][c] = true;
                    //init row, col
                    int index = 0;

                    check = bt(board, r, c, visited, index, word);
                    //visited[r][c] = false;
                }

                if(check){
                    return check;
                }
            }
        }
        return res;
        //iterate thru the matrix until we hit the first letter in the word
        //run bt

    }
};
