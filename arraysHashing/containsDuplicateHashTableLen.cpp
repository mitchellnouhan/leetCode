class Solution {
public:
    unordered_map<int, bool> present;

    bool hasDuplicate(vector<int>& nums) {
        for(int num: nums){
            present[num] = true;
        }
        return nums.size() > present.size();
    }
};
