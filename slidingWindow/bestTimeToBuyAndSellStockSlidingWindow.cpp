class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int b = 0;
        int s = 0;
        while (s < prices.size()){
            int cur_prof = prices[s] - prices[b];
            if (cur_prof < 0)
                b = s;
            else{
                res = max(res, cur_prof);
                s++;
            }
        }
        return res;
    }
};
