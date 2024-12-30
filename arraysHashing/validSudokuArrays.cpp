class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector <int>> rows(9, vector<int>(9,0));
        vector<vector <int>> cols(9, vector<int>(9,0));
        vector<vector <int>> subs(9, vector<int>(9,0));
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[row].size(); col++){
                char cur = board[row][col];
                if(cur != '.'){
                    int num = cur - '0' - 1;
                    int subs_ind = (3 * (row / 3)) + (col / 3);
                    if(rows[row][num] || cols[col][num]|| subs[subs_ind][num]){
                        return false;
                    }
                    rows[row][num]++;
                    cols[col][num]++;
                    subs[subs_ind][num]++;
                }
            }
        }
        return true;
    }
};
