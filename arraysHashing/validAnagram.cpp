class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int arr[26] = {0};
        for(int i = 0; i < s.length(); i++){
            arr[s[i] - 'a'] += 1;
            arr[t[i] - 'a'] -= 1;
        }

        for(int i = 0; i < 26; i++){
            if(arr[i])
                return false;
        }
        return true;
    }
};
