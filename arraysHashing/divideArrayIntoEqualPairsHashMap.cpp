class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> num_to_freq;
        for(int num: nums){
            if(num_to_freq.count(num) == 0){
                num_to_freq[num] = 0;
            }
            num_to_freq[num]++;
        }

        for(const auto elem: num_to_freq){
            if(elem.second % 2){
                return false;
            }
        }
        return true;
    }
};
/*
create a freq hash map based on nums
each elem of the hash map must be divisble by two 
*/