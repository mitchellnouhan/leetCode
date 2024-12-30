class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a hash map
        // key is the letter freq arrary of a given string
        // value is a string in a vector of strings 
        unordered_map< string, vector<string>> letterFreq_str;

        // iterate through each str in strs
        for(string str: strs){
            vector<int> letter_freq(26, 0);
            for(char c: str){
                letter_freq[c - 'a']++;
            }
            string key;
            for(int i = 0; i < 26; i++){
                key += ',' + to_string(letter_freq[i]);
            }
            letterFreq_str[key].push_back(str);

        }
        // create letter freq array for str
        // push str onto freq array key's vector
        // create res vector
        // iterate through entire unordered map and push vector of strings onto res
        // return res
        vector<vector<string>> res;
        for(auto elem: letterFreq_str){
            res.push_back(elem.second);
        }
        return res;
    }
};
