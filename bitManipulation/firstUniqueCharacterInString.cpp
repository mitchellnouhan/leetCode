class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char_to_freq(26, 0);
        for(char c: s){
            char_to_freq[c - 'a']++;
        }
        for(int i = 0; i < s.size(); i++){
            if(char_to_freq[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};