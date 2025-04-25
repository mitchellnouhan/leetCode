class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0;
        vector<int> bit_freq(32, 0);
        for(int num: nums){
            for(int i = 0; i < 32; i++){
                int mask = 0x80000000 >> i;
                bit_freq[i] = (mask & num) ? (bit_freq[i] + 1) : (bit_freq[i]);
            }
        }
        for(int i = 0; i < bit_freq.size(); i++){
            int mask = 0x80000000 >> i;
            if(bit_freq[i] >= k){
                res |= mask;
            }
        }
        return res;
    }
};