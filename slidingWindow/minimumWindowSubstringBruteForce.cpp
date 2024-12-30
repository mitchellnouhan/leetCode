class Solution {
public:
    void printVector(vector<int> v){
        cout << "Printing Vector:\n";
        for(int i: v)
            cout << i << ",";
        cout << "\n";
    }
    void printSubString(int start, int end, string s){
        cout << "Printing Substring:\n";
        for(int i = start; i < end; i++){
            cout << s[i];
        }
        cout << "\n";
    }
    string getSubString(int start, int end, string s){
        string sub;
        for(int i = start; i < end; i++){
            sub.push_back(s[i]);
        }
        return sub;
    }
    vector<int> get_freq(int start, int end, string s){
        vector<int> freq(52, 0);
        for(int i = start; i < end; i++){
            //cout << s[i] << " "
            int index = s[i] - 'A';
            if(s[i] >= 'a'){
                index = s[i] - 'a' + 26;
            }
            freq[index]++;
        } 
        return freq;
    }
    bool verifyFreqs(vector<int> t, vector<int> sub){
        bool res = true;
        for(int i = 0; i < t.size(); i++){
            if(t[i] > sub[i]){
                return false;
            }
        }
        return res;
    }
    string minWindow(string s, string t) {
        string res = "";
        pair<int, int> indexes;
        // Mitch's brute foce approach:
        // for every substring of s of len of t or greater
        // check that t's letter are present in substring
        // if so, then update res w/ current substring if it's greater than ""
        if(t.size() > s.size())
            return res;
        
        //get t's letter freq vector
        vector<int> t_freq = get_freq(0, t.size(), t);

        for(int i = 0; i < s.size() - (t.size() - 1); i++){
            for(int j = i + t.size() - 1; j < s.size(); j++){
                //printSubString(i, j + 1, s);
               
                //we have the start and end points of the substrings
                //get the letter freq of substring
                vector<int> s_sub_freq = get_freq(i, j + 1, s);
                
                if(verifyFreqs(t_freq, s_sub_freq) && (res == "" || res.size() > (j + 1 - i))){
                    //printVector(t_freq);
                    //printSubString(i, j + 1, s);
                    //printVector(s_sub_freq);
                    //cout << "BOOM\n";
                    res = getSubString(i, j + 1, s);
                    //cout << "res: " << res << "\n";
                }
            }
        }
        return res;
    }
};
