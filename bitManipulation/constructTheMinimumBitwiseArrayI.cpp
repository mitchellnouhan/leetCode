class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            for(int start = nums[i] - 1; start >= 1; start--){
                if((start | start + 1) == nums[i]){
                    res[i] = start;
                }
            }
        }
        return res;
    }
};