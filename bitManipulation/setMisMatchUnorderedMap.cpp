class Solution {
public:
    unordered_map<int, int> freq;

    vector<int> findErrorNums(vector<int>& nums) {
        for(int num: nums){
            freq[num] = (freq.count(num) == 0) ? 1 : freq[num] + 1;
        }
        int repeat = 0;
        int missing = 0;
        for(int i = 0; i < nums.size(); i++){
            if(freq.count(i + 1) == 0){
                missing = i + 1;
            }
            else if(freq[i + 1] == 2){
                repeat = i + 1;
            }
        }
        return {repeat, missing};
    }
};