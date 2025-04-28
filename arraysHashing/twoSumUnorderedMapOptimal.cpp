class Solution {
public:
    unordered_map<int, int> num_to_ind;

    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int look = target - num;

            if(num_to_ind.count(look) && i != num_to_ind[look]){
                return {num_to_ind[look], i};
            }

            num_to_ind[num] = i;
        }
    }
};
