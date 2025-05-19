class Solution {
public:
    int rows;
    int cols;

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited_land, int r, int c, int* res){
        //base cases
        //out of bounds or water
        if(((r < 0 || r >= this -> rows) || (c < 0 || c >= this -> cols)) || (grid[r][c] == 0)){
            *res += 1;
            return;
        }
        //visited land
        if(visited_land[r][c]){
            return;
        }

        //recursive cases
        //non visited land
        visited_land[r][c] = true;
        vector<vector<int>> neighbors = {
            // right, down, left, up
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };
        for(const auto& nei: neighbors){        
            int r_nei = r + nei[0]; 
            int c_nei = c + nei[1];
            dfs(grid, visited_land, r_nei, c_nei, res);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;

        this -> rows = grid.size();
        this -> cols = grid[0].size();

        vector<bool> row(this -> cols, 0);
        vector<vector<bool>> visited_land(this -> rows, row);

        for(int r = 0; r < this -> rows; r++){
            for(int c = 0; c < this -> cols; c++){
                if(grid[r][c]){
                    dfs(grid, visited_land, r, c, &res);
                    return res;
                }
            }
        }
        return -1;
    }
};