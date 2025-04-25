class Solution {
public:
    unordered_map<int, int> num_to_pres;

    void calcPres(vector<int>& nums, int i){
        for(int num: nums){
            if(num_to_pres.count(num) == 0){ // do we need
                num_to_pres[num] = 0;
            }
            num_to_pres[num] |= (1 << i);
        }
    }

    int calcBits(int pres){
        int res = 0;
        for(int i = 0; i < 3; i++){
            int mask = 1 << i;
            if(pres & mask){
                res++;
            }
        }
        return res;
    }
    
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> res;
        calcPres(nums1, 0);
        calcPres(nums2, 1);
        calcPres(nums3, 2);
        for(const auto elem: num_to_pres){
            if(calcBits(elem.second) > 1){
                res.push_back(elem.first);
            }
        }
        return res;
    }
};