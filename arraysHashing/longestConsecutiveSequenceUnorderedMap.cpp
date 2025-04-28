class Solution {
public:
    unordered_map<int, bool> present;

    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            present[num] = true;
        }

        for(const auto elem: present){
            int num = elem.first;
            if(present.count(num - 1) == 0){
                int cur = 1;
                while(present.count(num + cur)){
                    cur++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
