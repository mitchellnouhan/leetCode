class BrowserHistory {
public:
    int i;
    int n;
    vector<string> browser_history;

    BrowserHistory(string homepage) {
        n = 1;
        i = 0;
        browser_history = {homepage};
    }
    
    void visit(string url) {
        if(i == browser_history.size() - 1){
            browser_history.push_back(url);
            i++;
            n++;
        }
        else{
            i++;
            browser_history[i] = url;
            n = i + 1;
        }
    }
    
    string back(int steps) {
        i = (steps > i) ? 0 : (i - steps);
        return browser_history[i];
    }
    
    string forward(int steps) {
        i = (i + steps > n - 1) ? (n - 1) : (i + steps);
        return browser_history[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */