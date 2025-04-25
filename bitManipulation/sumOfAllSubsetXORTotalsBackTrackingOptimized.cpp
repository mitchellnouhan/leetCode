class Solution {
public:
    void bt(vector<int>& nums, int& xor_total, int i, int& res){
        if(i >= nums.size()){
            res += xor_total;
            return;
        }
        xor_total ^= nums[i];
        bt(nums, xor_total, i + 1, res);
        xor_total ^= nums[i];
        bt(nums, xor_total, i + 1, res);
    }

    int subsetXORSum(vector<int>& nums) {
        int xor_total = 0;
        int i = 0;
        int res = 0;
        bt(nums, xor_total, i, res);
        return res;
    }
};
/*
*/