class Solution {
public:
    int rows;
    int cols; 

    int countShoreLine(vector<vector<int>>& grid, int r, int c){
        int right = (c == this -> cols - 1) ? (1) : (!grid[r][c + 1]);
        int down = (r == this -> rows - 1) ? (1) : (!grid[r + 1][c]);
        int left = (c == 0) ? (1) : (!grid[r][c - 1]);
        int up = (r == 0) ? (1) : (!grid[r - 1][c]);
        return right + down + left + up;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        this -> rows = grid.size();
        this -> cols = grid[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                res = (grid[r][c]) ? (res + countShoreLine(grid, r, c)) : (res);
            }
        }
        return res;
    }
};