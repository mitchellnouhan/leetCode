class Solution {
public:
    vector<vector<int>> subsets;
    void calcSubSets(vector<int>& nums, vector<int>& subset, int i){
        // base cases
        if(i >= nums.size()){
            subsets.push_back(subset);
            return;
        }

        // recursive case
        subset.push_back(nums[i]);
        calcSubSets(nums, subset, i + 1);
        subset.pop_back();
        calcSubSets(nums, subset, i + 1);
    }

    int subsetXORSum(vector<int>& nums) {
        
        int i = 0;
        vector<int> subset = {};
        calcSubSets(nums, subset, i);
        
        int res = 0;
        for(const auto subset: subsets){
            int cur_xor = 0;
            for(int num: subset){
                cur_xor ^= num;
            }
            res += cur_xor;
        }
        return res;
    }
};