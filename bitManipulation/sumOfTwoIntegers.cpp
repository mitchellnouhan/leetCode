class Solution {
public:
    void printBinary(int num){
        uint32_t number = (uint32_t)num;
        printf("number: %i\n", number);
        uint32_t bitMask = 1<<31;
        int bitsInInt = 32; 
        std::cout << "Printing out " << num << " in binary form\n";
        for (int i = 0; i < bitsInInt; i++){
            //printf("number & bitMask: %i\n", number & bitMask);
            //printf("bitsInInt - i - 1: %i\n",bitsInInt - i - 1);
            //printf("(number & bitMask) >> (bitsInInt - i - 1): %i\n", (number & bitMask) >> (bitsInInt - i - 1));
            uint32_t bit = (number & bitMask) >> (bitsInInt - i - 1);
            //printf("%i\n", bit);
            std::cout << bit;
            bitMask >>= 1;
        }
        std::cout << "\n";
         
    }
    int getSum(int a, int b) {
        int res = 0;
        int bitsInInt = 32;
        uint32_t carryOver = 0;
        for (int i = 0; i < bitsInInt; i++){
            //use i index to define bitMask
            uint32_t bitMask = 1 << i;

            //grab the a & b bits of interest
            uint32_t aBit = a & bitMask;
            uint32_t bBit = b & bitMask;

            //XOR calculation for current sum calc
            uint32_t resBit = aBit ^ bBit ^ carryOver;

            //assign resBit to res
            res |= resBit;

            //update carryOver
            if (i < bitsInInt - 1){
                carryOver = ((aBit & bBit) | ((aBit ^ bBit) & carryOver)) << 1;
            }  
        }
        return res; 
    }
};