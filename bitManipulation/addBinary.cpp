class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int a_i = a.size() - 1;
        int b_i = b.size() - 1;
        int carry = 0;
        while(a_i >= 0 || b_i >= 0 || carry){
            int sum = carry;
            if(a_i >= 0){
                sum += a[a_i] - '0'; 
            }
            if(b_i >= 0){
                sum += b[b_i] - '0';
            }
            res = (sum % 2) ? ("1" + res) : ("0" + res);
            carry = (sum > 1) ? 1 : 0;
            a_i--;
            b_i--;
        }
        return (carry) ? ("1" + res) : res;
    }
};