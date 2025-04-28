class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0;
        int odd = 0;
        for(int i = 0; i < 32; i++){
            int mask = 1 << (31 - i);
            int index = i + 1;
            if((index % 2 == 0) && (mask & n)){
                even++;
            }
            if((index % 2) && (mask & n)){
                odd++;
            }
        }
        return {even, odd};
    }
};