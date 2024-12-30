class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        int r = 0;
        vector<int> freq(128, 0);
        while (r < s.size()){
            while(freq[s[r]]){
                freq[s[l]]--;
                l++;
            }
            freq[s[r]]++;
            r++;
            res = max(res, r - l);
        }
        return res;
    }
};
