class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> present;
        for(int i = 0; i < nums.size(); i++){
            if(present.count(nums[i]) && (i - present[nums[i]]) <= k){
                return true;
            }
            present[nums[i]] = i;
        }
        return false;
    }
};