class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res(nums.size(), false);
        int ones_digit = 0;
        for(int i = 0; i < nums.size(); i++){
            ones_digit = (2 * ones_digit + nums[i]) % 10;
            res[i] = (ones_digit % 5) ? false : true;
        }
        return res;
    }
};