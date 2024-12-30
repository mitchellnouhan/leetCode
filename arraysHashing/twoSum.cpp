class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index;
        for(int i = 0; i < nums.size(); i++){
            int look = target - nums[i];
            if(num_to_index.count(look) && i != num_to_index[look])
                return {num_to_index[look], i};
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};
