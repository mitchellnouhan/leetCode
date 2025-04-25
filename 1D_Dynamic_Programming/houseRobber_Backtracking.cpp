class Solution {
public:
    int dfs(vector<int>& nums, int index){
        if (index >= nums.size()){
            return 0;
        }
        return max(nums[index] + dfs(nums, index + 2), dfs(nums, index + 1));
    }

    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }
};