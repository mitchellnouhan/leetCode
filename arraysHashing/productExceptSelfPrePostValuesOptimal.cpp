class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // optimal preduct and postduct vectors
        // instead of storing preduct and postduct values
        // in vectors, calculate the preduct & postduct
        // values as you iterate thru nums;
        // store the appropriate values
        // in the the output vector as you iterate and calc
        // the running preduct or postduct values
        vector<int> res(nums.size(), 1);
        int preduct = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] *= preduct;
            preduct *= nums[i];
        }
        int postduct = 1;
        for(int i = nums.size() -1; i >= 0; i--){
            res[i] *= postduct;
            postduct *= nums[i];
        }
        return res;
    }
};
