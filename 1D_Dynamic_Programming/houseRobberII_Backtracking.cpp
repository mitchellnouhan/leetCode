class Solution {
public:
    int dfs(vector<int>& nums, int i, int start){
        if(i >= nums.size() || (start == 0 && i == nums.size() - 1)){
            return 0;
        }
        return max(nums[i] + dfs(nums, i + 2, start), dfs(nums, i + 1, start));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(dfs(nums, 0, 0), dfs(nums, 1, 1));
    }
};
