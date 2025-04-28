class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> tab = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            tab.push_back(max(nums[nums.size() - 1 - i] + tab[i], tab[i + 1]));
        }
        return tab[tab.size() - 1];
    }
};
