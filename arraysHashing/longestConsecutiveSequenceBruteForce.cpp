class Solution {
public:
    bool isPresent(int val, vector<int>& nums, int index){
        for(int j = 0; j < nums.size(); j++){
            if(j != index && nums[j] == val){
                return true;
            }
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int cur = 1;
            while(isPresent(nums[i] + cur, nums, i)){
                cur++;
            }
            res = max(res, cur);
        }
        return res;
    }
};
