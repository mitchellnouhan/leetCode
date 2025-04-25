class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        vector<bool> freq(26, false);
        for(char c: allowed){
            freq[c - 'a'] = true;
        }

        for(const auto word: words){
            bool consistent = true;
            for(char c: word){
                if(!freq[c - 'a']){
                    consistent = false;
                }
            }
            if(consistent){
                res++;
            }
        }
        return res;
    }
};