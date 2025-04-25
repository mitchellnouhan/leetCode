class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> letter_freq(26, 0);
        for(char c: s){
            letter_freq[c - 'a']++;
        }
        int num_of_non_pairs = 0;
        for(int freq: letter_freq){
            if(freq % 2){
                num_of_non_pairs++;
            }
            if(num_of_non_pairs > 1){
                return false;
            }
        }
        return true;
    }
};