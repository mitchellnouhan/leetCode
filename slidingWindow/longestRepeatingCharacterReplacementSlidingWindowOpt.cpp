class Solution {
public:
    int depricated_max_freq(unordered_map<char, int> map){
        cout << "max_freq\n";
        int res = 0;
        for(auto elem: map){
            res = max(res, (int)elem.second);
        }
        cout << res << "\n";
        return res;
    }

    int characterReplacement(string s, int k) {
        int res = 0;

        unordered_map<char, int> freq;
        
        int l = 0;
        int max_freq = 0;
        for(int r = 0; r < s.size(); r++){
            //update hash map with r char
            if(freq.count(s[r]) == 0){
                freq[s[r]] = 0;
            }
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);

            // if the substring is not valid, update the 
            // substring until it is (update l pointer & hash)
            while((r - l + 1) - max_freq > k){
                freq[s[l]]--;
                l++;
            }
            //if the substring is valid, update cur len
            res = max(res, r - l + 1);

        }
        return res;   
    }
};
