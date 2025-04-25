class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        vector<int> res(nums.size() - 1, 0);
        for(int i = 0; i < nums.size() - 1; i++){
            res[i] = nums[i] | nums[i + 1];
        }
        return res;
    }
};