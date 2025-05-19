class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        int mask = 0x000003ff;
        for(int i = 0; i < n; i++){
            nums[i] |= (nums[nums[i]] & mask) << 10;
        }
        for(int i = 0; i < n; i++){
            nums[i] >>= 10;
        }
        return nums;
    }
};