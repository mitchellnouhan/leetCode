class Solution {
public:
    map<int, bool> present;
    int longestConsecutive(vector<int>& nums) {   
        int res = 0;
        for(int num: nums){
            present[num] = true;
        }

        int cur = 1;
        for(const auto elem: present){
            cur = (present.count(elem.first - 1) == 0) ? 1 : cur + 1;
            res = max(res, cur);
        } 
        return res;
    }
};
