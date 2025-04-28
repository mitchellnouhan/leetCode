class Solution {
public:
    int bit_num = 6;

    vector<int> bit_freq = {0, 0, 0, 0, 0, 0};

    void update_bit_freq(int num, int val){
        for(int i = 0; i < bit_num; i++){
            int mask = 1 << i;
            if(num & mask){
                bit_freq[bit_num - 1 - i] += val;
            }
        }
    }

    int calc_or_from_bit_freq(void){
        int res = 0;
        for(int i = 0; i < bit_num; i++){
            if(bit_freq[bit_num - 1 - i] > 0){
                res |= (1 << i);
            }
        }
        return res;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k == 0){
            return 1;
        }
        int res = INT_MAX;
        int l = 0;
        int r = 0;
        int cur_or = 0;
        while (r < nums.size()){
            while(r < nums.size() && cur_or < k){
                update_bit_freq(nums[r], 1);
                cur_or |= nums[r];
                r++;
            }

            while(l <= r && cur_or >= k){
                res = min(res, r - l);
                update_bit_freq(nums[l], -1);
                cur_or = calc_or_from_bit_freq();
                l++;
            }

        }
        return (res == INT_MAX) ? -1 : res;
    }
};