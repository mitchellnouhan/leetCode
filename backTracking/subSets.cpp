class Solution {
public:
    void bt(vector<int>& nums, vector<int>& cur_res, int index, vector<vector<int>>& res){
        //base case: we are at the end of our nums array or index == nums.size()
        if(index == nums.size()){
            res.push_back(cur_res);
            return;
        }

        cur_res.push_back(nums[index]);
        bt(nums, cur_res, index + 1, res);
        cur_res.pop_back();
        bt(nums, cur_res, index + 1, res);  
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        vector<int> cur_res = {};
        int index = 0;
        bt(nums, cur_res, index, res);
        return res;
    }
};
