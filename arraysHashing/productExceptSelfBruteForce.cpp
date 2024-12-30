class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //brute force method:
        // for each num in nums, we calculate the product except itself
        // by iterating through all of the nums again and excluding itself 
        // from the running product by checking indexes
        vector<int> res(nums.size(),1);
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i];
            for(int j = 0; j < nums.size(); j++){
                if(i != j){
                    res[i] *= nums[j];
                }
            }
        }
        return res;
    }
};
