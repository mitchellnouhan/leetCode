class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = 1001;
        int l = 0;
        int r = nums.size() - 1;
        while(nums[l] > nums[r]){
            int m = l + (r - l) / 2;
            res = min(res, nums[m]);
            //
            if(nums[l] > nums[m]){
                r = m - 1;
            }
            else if(nums[m] > nums[r]){
                l = m + 1;
            }
        }
        return min(res, nums[l]);
    }
};