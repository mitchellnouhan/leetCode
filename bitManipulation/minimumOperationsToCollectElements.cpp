class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        uint64_t k_bits = 0;
        uint64_t collected = ((uint64_t)1 << k) - 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res++;
            if(nums[i] <= k){
                k_bits |= ((uint64_t)1 << (nums[i] - 1));
                if(k_bits == collected){
                    return res;
                }
            }
        }
        return res;
    }
};