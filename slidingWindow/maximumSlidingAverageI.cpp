class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1 * INFINITY;
        int l = 0;
        int r = 0;
        double sum = 0;
        while(r < k){
            sum += nums[r++];
        }
        res = max(res, (sum/k));

        while(r < nums.size()){
            sum += (nums[r++] - nums[l++]);
            res = max(res, (sum/k));
        }
        return res;
    }
};