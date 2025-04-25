class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int num: nums){
            count = (num & 1) ? count : count + 1;
            if(count > 1){
                return true;
            }
        }
        return false;
    }
};