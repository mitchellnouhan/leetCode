class Solution {
public:
    unordered_set<int> present;

    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            present.insert(num);
        }
        
        for(int num: present){
            if(present.find(num - 1) == present.end()){
                int cur = 1;
                while(present.find(num + cur) != present.end()){
                    cur++;
                }
                res = max(res, cur);
            }
        }
        return res;
    }
};
