class Solution {
public:
    int n;
    
    void flip(vector<int>& row){
        int iterations = this -> n / 2;
        for(int i = 0; i < iterations; i++){
            int tmp = row[i];
            row[i] = row[n - 1 - i];
            row[n - 1 - i] = tmp;
        }
    }

    void invert(vector<int>& row){
        for(int i = 0; i < this -> n; i++){
            row[i] = (row[i] + 1) % 2;
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        this -> n = image.size();
        for(int i = 0; i < this -> n; i++){
            flip(image[i]);
            invert(image[i]);
        }
        return image;
    }
};