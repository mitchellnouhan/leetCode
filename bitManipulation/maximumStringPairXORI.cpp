class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        /*
        -iterate thru nums and generate pairs
        -calc if they're strong 
        -if they're strong update the res with the xor of strong pair using max function 
        */
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int x = nums[i];
                int y = nums[j];
                if(abs(x - y) <= min(x,y)){
                    res = max(res, x ^ y);
                }
            }
        }
        return res;
    }
};