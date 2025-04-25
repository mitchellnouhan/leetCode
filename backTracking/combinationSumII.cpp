class Solution {
public:
    vector<vector<int>> res;

    bool bt(vector<int>& candidates, int target, int index, vector<int>& cur_res){
        if(target == 0){
            res.push_back(cur_res);
        }
        if(target <= 0 || index == candidates.size()){
            return false;
        }

        cur_res.push_back(candidates[index]);
        bool explore = bt(candidates, target - candidates[index], index + 1, cur_res);
        cur_res.pop_back();
        if(explore){
            while(index + 1 < candidates.size() && candidates[index] == candidates[index + 1]){
                index++;
            }
            bt(candidates, target, index + 1, cur_res);
        }
        return true;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int index = 0;
        vector<int> cur_res = {};
        bt(candidates, target, index, cur_res);
        return res;
    }
};
