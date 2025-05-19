class Solution {
public:
    map<int, vector<int>> bit_num;
    int countBits(int num){
        int res = 0;
        for(int i = 0; i < 14; i++){
            int mask = 1 << i;
            if(num & mask){
                res++;
            }
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        for(int num: arr){
            bit_num[countBits(num)].push_back(num);
        }
        for(auto elem: bit_num){
            sort(elem.second.begin(), elem.second.end());
            for(int num: elem.second){
                res.push_back(num);
            }
        }
        return res;
    }
};