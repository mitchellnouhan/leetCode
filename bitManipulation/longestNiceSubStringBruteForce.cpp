class Solution {
public:
    bool isNice(string s){
        int uppercase = 0;
        int lowercase = 0;

        for(char c: s){
            if('A' <= c && c <= 'Z'){
                uppercase |= (1 << (c - 'A'));
            }
            else{
                lowercase |= (1 << (c - 'a'));
            }
        }

        for(int i = 0; i < 26; i++){
            int mask = 1 << i;
            if((mask & uppercase) ^ (mask & lowercase)){
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            for(int j = i + 1; j < s.size(); j++){
                string cur = s.substr(i, j - i + 1);
                if(isNice(cur) && cur.size() > res.size()){
                    res = cur;
                }
            }
        }
        return res;
    }
};