class Solution {
public:
    vector<int> flip(vector<int> row){
        int n = row.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            res[n - 1 - i] = row[i];
        }
        return res; 
    }

    vector<int> invert(vector<int> row){
        int n = row.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            res[i] = (row[i] + 1) % 2;
        }
        return res;
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        //init res
        int n = image.size();
        vector<int> row(n, 0);
        vector<vector<int>> res(n, row);

        // for each row:
        //flip
        //invert
        for(int r = 0; r < n; r++){
            res[r] = invert(flip(image[r]));
        }

        return res;
    }
};