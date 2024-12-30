class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2){
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r){
                if (nums[i] + nums[l] + nums[r] > 0)
                    r -= 1;
                else if (nums[i] + nums[l] + nums[r] < 0)
                    l += 1;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    r -= 1;
                    while (l < r && nums[l] == nums[l - 1])
                        l += 1;
                    while (l < r && nums[r] == nums[r + 1])
                        r -= 1;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
            i++;
        }
        return res;
    }
};
