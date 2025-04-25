class Solution {
public:
    unordered_map<int, int> num_to_ind;

    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            num_to_ind[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int look = target - nums[i];
            if(num_to_ind[look] && i != num_to_ind[look]){
                return {i, num_to_ind[look]};
            }
        }
    }
};
