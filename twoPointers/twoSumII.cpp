class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r){
            int cur_sum = numbers[l] + numbers[r];
            if(cur_sum > target)
                r--;
            else if(cur_sum < target)
                l++;
            else
                return {l + 1, r + 1};
        }
        return {0, 0};
    }
};