class Solution {
public:
    void depricated_printMap(unordered_map<char, int> map){
        cout << "\n" << "Printing Map:\n";
        for(auto elem: map){
            cout << "key:val ";
            cout << elem.first << ":" << elem.second << "\n";
        }
        cout << "\n";
    }
    vector<int> get_freq(int start, int end, string s){
        vector<int> freq(26, 0);
        for(int i = start; i < end; i++)
            freq[s[i] - 'a']++;
        return freq;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        //get s1 hash & prelim s2 sub hash
        vector<int> s1_freq = get_freq(0, s1.size(), s1);
        vector<int> s2_freq(26, 0);
        //unordered_map<char, int> s2_freq = get_req(0, s1.size(), s2);
        //calc first s2 sub hash
        int l = 0;
        int r = 0;
        while ((r - l + 1) <= s1.size()){
            s2_freq[s2[r] - 'a']++;
            r++;
        }
        //printMap(s2_freq);
        while(r < s2.size() && s2_freq != s1_freq){
            //printMap(s2_freq);
            s2_freq[s2[l] - 'a']--;
            l++;
            s2_freq[s2[r] - 'a']++;
            r++;
        }
        return (bool)(s2_freq == s1_freq);
        /*
        //unordered_map<char, int> s2_sub_freq = get_freq(i, end, s2);
        for(int i = 0; i < s2.size() - (s1.size() - 1); i++){
            if(s2_freq == s1_freq)
                return true;
            
        }
        return false;
        */
    }
};
