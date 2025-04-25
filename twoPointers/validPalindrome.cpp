class Solution {
public:
    bool isPalindrome(string s) {
        //use two pointers(indexes)
        //start on both sides of the string
        //adjust both pointers until both are pointing
        //to alphanum chars
        //if different, then we know this isn't a palindrome
        //continue this entire process until the two pointers
        //cross over
        int l = 0;
        int r = s.size() - 1;

        while (l <= r){
            while (l <= r && isalnum(s[l]) == 0)
                l++;
            while (l <= r && isalnum(s[r]) == 0)
                r--;
            if(l <= r && tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};
