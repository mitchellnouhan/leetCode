class Solution {
public:
    void bt(int o, int c, string stack, vector<string>& res){
        if (o == 0 && c == 0){
            res.push_back(stack);
            return;
        }

        if(o == c)
            bt(o - 1, c, stack + '(', res);
        else if(o == 0)
            bt(o, c - 1, stack + ')', res);
        else if(o < c){
            bt(o - 1, c, stack + '(', res);
            bt(o, c - 1, stack + ')', res);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        bt(n, n, stack, res);
        return res;
    }
};
