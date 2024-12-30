class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded;
        for(string str: strs){
            encoded += to_string(str.size());
            encoded += ',';
            for(char c: str)
                encoded += c;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()){
            int num = 0;
            while(i < s.size() && s[i] != ','){
                num *= 10;
                num += s[i] - '0';
                i += 1;
            }
            i += 1;
            string str = "";
            for(int j = 0; j < num; j++){
                str += s[i + j];
            }
            i += num;
            decoded.push_back(str);   
        }
        return decoded;
    }
};
