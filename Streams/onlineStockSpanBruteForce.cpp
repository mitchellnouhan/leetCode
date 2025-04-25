class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        prices = {};
    }
    
    int next(int price) {
        int res = 0;
        prices.push_back(price);
        int i = prices.size() - 1;
        while(i >= 0 && prices[i] <= prices[prices.size() - 1]){
            i--;
            res++;
        }
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */