class Solution {
public:
    void printString(int start, int end, string s){
        for(int i = start; i < end + 1; i++){
            cout << s[i];
        }
        cout << "\n";
    }
    bool stringValid(int start, int end, string s, int k){
        //hash map
        unordered_map<char, int> letter_freq;

        //get freq of all letters
        for(int i = start; i < end + 1; i++){
            if(letter_freq.count(s[i]) == 0){
                letter_freq[s[i]] = 0;
            }
            letter_freq[s[i]]++;
        }

        //get max val
        int max_freq = 0;
        for(auto elem: letter_freq){
            max_freq = max(max_freq, elem.second);
        }
        return (((end - start + 1) - (max_freq)) <= k);
    }
    int characterReplacement(string s, int k) {
        //mitch's brute force attempt
        //goal is to generate all substring
        //feed each substring into a valid function
        //if valid, update a res variable
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                //cout << "i,j:" << i << "," << j << "\n";
                //printString(i, j, s);
                //cout << stringValid(i, j, s, k) << "\n";
                if(stringValid(i, j, s, k))
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};
