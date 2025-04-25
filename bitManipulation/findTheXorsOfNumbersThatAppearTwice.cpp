class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        /*
        iterate thru nums and store their precence in a 64 bit data type (double)
        since each number in nums only appears once or twice, if num is already present, it's in twice
        xor that number to the res
        */
        int res = 0; 
        uint64_t present = 0;
        for(int num: nums){
            uint64_t mask = ((uint64_t)1 << num);
            if(present & mask){
                res ^= num;
            }
            present |= mask;
        }
        return res;
    }
};