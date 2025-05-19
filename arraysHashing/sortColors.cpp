class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color_freq(3, 0);
        for(int num: nums){
            color_freq[num]++;
        }
        int color = 0;
        for(int i = 0; i < nums.size(); i++){
            while(color_freq[color] == 0){
                color++;
            }
            nums[i] = color;
            color_freq[color]--;
        }
    }
};