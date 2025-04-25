class Solution {
public:
    set<int> present;
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            present.insert(num);
        }

        int cur = 1;
        for(int num: present){
            cur = (present.find(num - 1) == present.end()) ? 1 : cur + 1;
            res = max(res, cur);
        }
        return res;
    }
};
