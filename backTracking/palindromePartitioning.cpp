class Solution {
public:
    vector<vector<string>> res;
    bool is_palindrome(int l, int r, string s){
        while (l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void dfs(int i, vector<string>& par, string& s){
        //base case
        if(i == s.size()){
            res.push_back(par);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(is_palindrome(i, j, s)){
                par.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, par, s);
                par.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> par = {};
        dfs(0, par, s);
        return res;
    }
};
