class Solution {
public:
    unordered_map<char, int> freq;
    
    bool isAnagram(string s, string t) {
        for(char l: s){
            freq[l] = (freq.count(l) == 0) ? 1 : freq[l] + 1; 
        }
        for(char l: t){
            freq[l]--;
        }
        for(const auto elem: freq){
            if(elem.second){
                return false;
            }
        }
        return true;
    }
};
