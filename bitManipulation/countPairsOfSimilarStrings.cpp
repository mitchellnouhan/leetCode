class Solution {
public:
    unordered_map<int, int> letters_to_freq;
    int similarPairs(vector<string>& words) {
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int letters = 0;
            for(char c: word){
                letters |= (1 << (c - 'a'));
            }
            
            if(letters_to_freq.count(letters) == 0){
                letters_to_freq[letters] = 0;
            }
            letters_to_freq[letters]++;
        }
        for(const auto elem: letters_to_freq){
            if(elem.second > 1){
                res += ((elem.second * (elem.second - 1)) / 2);
            }
        }
        return res;
    }
};