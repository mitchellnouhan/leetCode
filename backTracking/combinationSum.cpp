class Solution {
public:
    void bt(vector<int>& nums, int index, vector<int>& cur_res, int cur_sum, vector<vector<int>>& res, int target){
        //base case(s)
        /*
        1. cur_sum == target
            add cur_res to res
            return
             
        2. cur_sum > target
            return
        */
        if(cur_sum == target){
            res.push_back(cur_res);
        }
        if(cur_sum >= target){
            return;
        }
        

        //recursive case(s)
        /*
        for each remaining number in nums(nums[index:])
            check for combination sum
        */
        for(int i = index; i < nums.size(); i++){
            cur_res.push_back(nums[i]);
            bt(nums, i, cur_res, cur_sum + nums[i], res, target);
            cur_res.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res = {};
        vector<int> cur_res {};
        int cur_sum = 0;
        int index = 0;
        bt(nums, index, cur_res, cur_sum, res, target);
        return res;
    }
};
