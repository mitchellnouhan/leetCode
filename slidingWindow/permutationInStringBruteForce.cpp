class Solution {
public:
    void printMap(unordered_map<char, int> map){
        cout << "\n" << "Printing Map:\n";
        for(auto elem: map){
            cout << "key:val ";
            cout << elem.first << ":" << elem.second << "\n";
        }
        cout << "\n";
    }
    unordered_map<char, int> get_freq(int start, int end, string s){
        unordered_map <char, int> freq;
        for(int i = start; i < end; i++)
            freq[s[i]]++;
        return freq;
    }

    bool checkInclusion(string s1, string s2) {
        /*
        Mitch's Brute Force attempt:
        -Get s1's letter freq hash map
        -calc every s2 substring of equal len to s1 and it's respective letter freq hash map
        -if the s1 letter freq and s2 substring letter freq hash maps are equal, return true
        */
        //get s1 hash
        if(s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> s1_freq = get_freq(0, s1.size(), s1);
        //printMap(s1_freq);
        for(int i = 0; i < s2.size() - (s1.size() - 1); i++){
            
            int end = i + s1.size();
            /*
            for(int j = i; j < end; j++){
                cout << s2[j];
            }
            cout << "\n";
            */
            unordered_map<char, int> s2_sub_freq = get_freq(i, end, s2);
            if(s2_sub_freq == s1_freq)
                return true;
        }
        return false;
    }
};
