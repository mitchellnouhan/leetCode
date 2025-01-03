class Solution {
public:
    vector<vector<int>> res;

    void bt(vector<int>& nums, int index, vector<int>& cur_res){
        if(index == nums.size()){
            res.push_back(cur_res);
            return;
        }

        cur_res.push_back(nums[index]);
        bt(nums, index + 1, cur_res);
        cur_res.pop_back();

        while(index + 1 < nums.size() && nums[index] == nums[index + 1]){
            index++;
        }
        
        bt(nums, index + 1, cur_res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        vector<int> cur_res = {};
        bt(nums, index, cur_res);
        return res;
    }
};
