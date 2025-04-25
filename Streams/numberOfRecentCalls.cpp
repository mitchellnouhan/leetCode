class RecentCounter {
public:
    deque<int> requests;

    RecentCounter() {
        requests = {};
    }
    
    int ping(int t) {
        requests.push_back(t);
        while(requests[0] < (t - 3000)){
            requests.pop_front();
        }
        return requests.size();     
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */