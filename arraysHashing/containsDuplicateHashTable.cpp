class Solution {
public:
    unordered_map<int, bool> present;

    bool hasDuplicate(vector<int>& nums) {
        for(int num: nums){
            if(present.count(num)){
                return true;
            }
            present[num] = true;
        }
        return false;
    }
};
