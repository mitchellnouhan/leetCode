class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //create a num freq HashMap
        unordered_map<int, int> freq_hash_map;
        for(int num: nums){
            if(freq_hash_map.count(num) == 0)
                freq_hash_map[num] = 0;
            freq_hash_map[num]++;
        }

        //sort the freq HashMap based on freq in descending order
        //create vector of int pairs
        vector<pair<int, int>> freq_num;
        for(auto p: freq_hash_map){
            //port over the freq_hash_map num,freq pairs into array
            //but in freq,num order so the vector can be sorted
            //based on freq
            freq_num.push_back({p.second, p.first});
        }
        //sort in descending order
        sort(freq_num.rbegin(), freq_num.rend());
        
        //create vector of the first k values of the sorted hashMap
        vector<int> res;
        //push second elem of pair since we want to return num
        for(int i = 0; i < k; i++){
            res.push_back(freq_num[i].second);
        }
        return res;
    }
};
