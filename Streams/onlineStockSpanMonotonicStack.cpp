class StockSpanner {
public:
    stack<pair<int, int>> s;
    int t;

    StockSpanner() {
        t = 0;
    }
    
    int next(int price) {
        pair<int, int> cur = {price, t};
        while(!s.empty() && price >= s.top().first){
            cur.second = s.top().second;
            s.pop();
        }
        s.push(cur);
        t++;
        return t - s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */