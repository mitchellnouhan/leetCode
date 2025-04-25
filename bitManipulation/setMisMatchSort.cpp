class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int repeat = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                repeat = nums[i];
            }
        }
        int missing = repeat;
        for(int i = 0; i < nums.size(); i++){
            missing += (i + 1);
            missing -= (nums[i]);
        }
        return {repeat, missing};
    }
};