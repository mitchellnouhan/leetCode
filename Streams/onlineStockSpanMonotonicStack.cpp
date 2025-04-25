class StockSpanner {
public:
    // where price, time
    stack<pair<int, int>> s;
    int t;

    StockSpanner() {
        t = 0;
    }
    
    int next(int price) {
        int res = 0;
        //monotonic decreasing stack
        //push onto stack if it's empty or if cur price is less than top of the stack
        if(s.empty() || price < s.top().first){
            s.push({price, t});
        }

        pair<int, int> cur = {price, t};
        while(!s.empty() && price >= s.top().first){
            cur.second = s.top().second;
            s.pop();
        }
        
        s.push(cur);
        //increment time
        t++;

        return t - s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */