class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int ind = k;
        deque<int> d_tickets;
        for(int ticket: tickets){
            d_tickets.push_back(ticket);
        }
        // break when tickets[ind] > 1 or ind
        while(d_tickets[ind] > 1 || ind){
            // front of the queue buys ticket
            d_tickets[0]--;
            res++;

            // they move to the back of the line
            int person = d_tickets[0];
            d_tickets.pop_front();
            if(person > 0)
                d_tickets.push_back(person);
            
            // update ind
            ind = (ind == 0) ? (d_tickets.size() - 1) : (ind - 1);
        }
        return res + 1;
    }
};

