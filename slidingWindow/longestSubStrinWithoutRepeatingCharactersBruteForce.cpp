class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        int r = 0;
        while (r < s.size()){
            for(int i = l; i < r; i++){
                if(s[i] == s[r]){
                    l = i + 1;
                    break;
                }
            }
            r++;
            res = max(res, r - l);      
        }
        return res;
    }
};
