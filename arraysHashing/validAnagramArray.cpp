class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        for(char l: s){
            freq[l - 'a']++;
        }
        for(char l: t){
            freq[l - 'a']--;
        }
        for(int f: freq){
            if(f){
                return false;
            }
        }
        return true;
    }
};
