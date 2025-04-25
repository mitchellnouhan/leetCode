class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size() + 1; i++)
            res += i;
        for(int num: nums)
            res -= num;
        return res;  
    }
};
