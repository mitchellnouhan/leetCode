class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force method would be to check every possible
        // buy/sell comb and calc its respective profit
        // while iterating thru each option, keep track of the max profit
        int res = 0; int b = 0; int s = 0;
        for(int b = 0; b < prices.size(); b++){
            for(int s = b; s < prices.size(); s++)
                res = max(res, prices[s] - prices[b]);
        }
        return res;
    }
};
