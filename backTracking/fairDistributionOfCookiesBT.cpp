class Solution {
public:
    int k;
    int res;

    int unfairness(vector<int>& cookie_distro){
        int unfair = 0;
        for(int num: cookie_distro){
            unfair = max(unfair, num);
        }
        return unfair;
    }
    
    void bt_dfs(vector<int>& cookies, vector<int>& cookie_distro, int c_ind){
        // base case(s)
        if(c_ind >= cookies.size()){
            this -> res = min(this -> res, unfairness(cookie_distro));
            return;
        }

        // recursive case(s)
        for(int p = 0; p < this -> k; p++){
            cookie_distro[p] += cookies[c_ind];
            bt_dfs(cookies, cookie_distro, c_ind + 1);
            cookie_distro[p] -= cookies[c_ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        this -> k = k;
        this -> res = INT_MAX;
        vector<int> cookie_distro(this -> k, 0);
        bt_dfs(cookies, cookie_distro, 0);
        return this -> res;
    }
};