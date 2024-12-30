class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        vector<pair<int, int>> stack;

        for(int i = 0; i < temperatures.size(); i++){
            int cur_temp = temperatures[i];

            while(stack.size() && cur_temp > stack.back().first){
                res[stack.back().second] = i - stack.back().second;
                stack.pop_back(); 
            }
            stack.push_back({cur_temp, i});
        }
        return res;
    }
};
