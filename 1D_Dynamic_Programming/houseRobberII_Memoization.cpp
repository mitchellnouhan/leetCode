class Solution {
public:
    vector<vector<int>> memo;
    int dfs(vector<int>& nums, int i, int start){
        if(i >= nums.size() || (start == 0 && i == nums.size() - 1)){
           return 0;
        }
        if(memo[start][i] == -1){
            memo[start][i] = max(nums[i] + dfs(nums, i + 2, start), dfs(nums, i + 1, start));
        }
        return memo[start][i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> a_vec(nums.size() + 2, -1);
        memo.resize(2, a_vec);
        return max(dfs(nums, 0, 0), dfs(nums, 1, 1));
    }
};
