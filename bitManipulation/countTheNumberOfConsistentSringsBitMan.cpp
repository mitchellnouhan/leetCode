class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        /*
        instead of an array of booleans
        create a bitmask with one int!
        go thru each word
        go thru each char in word and check to see if that char is in the bitmask
        */
        int res = 0;
        int allowed_mask = 0;
        for(char c: allowed){
            allowed_mask |= (1 << (c - 'a'));
        }
        for(const auto word: words){
            bool con = true;
            for(char c: word){
                int cur_mask = 1 << (c - 'a');
                if((cur_mask & allowed_mask) == 0){
                    con = false;
                }
            }
            if(con){
                res++;
            }
        }
        return res;
    }
};