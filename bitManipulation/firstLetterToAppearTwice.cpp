class Solution {
public:
    char repeatedCharacter(string s) {
        char repeated = 'a';
        int letters = 0;
        for(char c: s){
            int c_bit = 1 << (c - 'a');
            if(letters & c_bit){
                return c;
            }
            letters |= c_bit;
        }
        return repeated;
    }
};