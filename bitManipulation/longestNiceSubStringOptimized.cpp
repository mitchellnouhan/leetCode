class Solution {
public:
    void updateBitField(int* uppercase, int* lowercase, char c){
        if('A' <= c && c <= 'Z'){
            *uppercase |= (1 << (c - 'A'));
        }
        else{
            *lowercase |= (1 << (c - 'a'));
        }
    }

    bool isNice(int* uppercase, int* lowercase){
        return (*uppercase ^ *lowercase) ? false : true;
    }

    string longestNiceSubstring(string s) {
        string res = "";
        int res_size = 0;
        for(int i = 0; i < s.size(); i++){
            int uppercase = 0;
            int lowercase = 0;
            string cur = "";
            int cur_size = 0;
            cur += s[i];
            updateBitField(&uppercase, &lowercase, s[i]);
            for(int j = i + 1; j < s.size(); j++){
                cur += s[j];
                cur_size = j - i + 1;
                updateBitField(&uppercase, &lowercase, s[j]);
                if(isNice(&uppercase, &lowercase) && cur_size > res_size){
                    res = cur;
                    res_size = cur_size;
                }
            }
        }
        return res;
    }
};