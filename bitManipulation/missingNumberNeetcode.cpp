class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++){
            res ^= i^nums[i];
        }
        return res^numsSize;
    }
};