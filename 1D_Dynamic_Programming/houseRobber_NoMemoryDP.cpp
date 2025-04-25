class Solution {
public:
    int rob(vector<int>& nums) {
        int back2 = 0;
        int back1 = 0;
        for(int i = 0; i < nums.size(); i++){
            int cur = max(nums[nums.size() - 1 - i] + back2, back1);
            back2 = back1;
            back1 = cur; 
        }
        return back1;
    }
};
