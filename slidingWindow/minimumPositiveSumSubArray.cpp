class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int min_pos_res = INT_MAX; int n = nums.size();
        for(int window_size = l; window_size <= r; window_size++){
            int i = 0; int j = 0; int cur = 0;
            while(j < n && (j - i + 1) < window_size){
                cur += nums[j++];
            }
            while(j < n){
                cur += nums[j++];
                min_pos_res = cur > 0 ? min(min_pos_res, cur) : min_pos_res;
                cur -= nums[i++];
            }
        }
        return min_pos_res == INT_MAX ? -1 : min_pos_res;
    }
};