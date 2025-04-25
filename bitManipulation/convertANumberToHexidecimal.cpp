class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        
        string res = "";
        uint32_t bitmask = 0xf0000000;

        int shift = 7;
        while((bitmask & num) == 0){
            bitmask >>= 4;
            shift--;
        }

        while(bitmask){
            uint32_t number = (bitmask & num) >> (4 * shift);
            char letter = (number < 10) ? (48 + number) : (97 + (number - 10));
            res += letter;
            bitmask >>= 4;
            shift--;
        }

        return res;
    }
};