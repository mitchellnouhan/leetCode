class Solution {
public:
    vector<vector<int>> res;
    
    void bt(vector<int>& nums, vector<int>& cur_perm, vector<bool>& visited){
        //base cases
        if(cur_perm.size() == nums.size()){
            res.push_back(cur_perm);
            return;
        }

        //recursive cases
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                cur_perm.push_back(nums[i]);
                visited[i] = true;
                bt(nums, cur_perm, visited);
                cur_perm.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur_perm = {};
        vector<bool> visited(nums.size(), false);
        bt(nums, cur_perm, visited);
        return res;
    }
};
