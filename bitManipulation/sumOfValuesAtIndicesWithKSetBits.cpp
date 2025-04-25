class Solution {
public:
    int countBits(int num){
        int res = 0;
        for(int i = 0; i < 32; i++){
            int mask = 1 << i;
            if(num & mask){
                res++;
            }
        }
        return res;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(countBits(i) == k){
                res += nums[i];
            }
        }
        return res;   
    }
};