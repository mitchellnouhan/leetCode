class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int, int>hashMap;
        for(int num: nums){
            if(hashMap.count(num))
                return true;
            hashMap[num] = 1;
        }   
        return false;
    }
};
