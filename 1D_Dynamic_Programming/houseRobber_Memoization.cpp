class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int>& nums, int i){
        if(i >= nums.size()){
            return 0;
        }
        if(memo.count(i) == 0)
            memo[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
