class Solution {
public:
    vector<string> res;
    vector<string> numToChars = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void bt(string& digits, string& cur_combo, int index){
        if(cur_combo.size() == digits.size()){
            res.push_back(cur_combo);
            return;
        }

        int cur_digit = digits[index] - '2';
        for(char c: numToChars[cur_digit]){
            cur_combo += c;
            bt(digits, cur_combo, index + 1);
            cur_combo.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        string cur_combo = "";
        int index = 0;
        bt(digits, cur_combo, index);
        return res;
    }
};
