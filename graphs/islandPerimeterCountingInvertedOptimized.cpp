class Solution {
public:
    int rows;
    int cols; 

    int countShoreLine(vector<vector<int>>& grid, int r, int c){
        int res = 4;
        // if left is land, subtract 2
        if(r && grid[r - 1][c]){
            res -= 2;
        }
        // if up is land, subtract 2
        if(c && grid[r][c - 1]){
            res -= 2;
        }
        return res;
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