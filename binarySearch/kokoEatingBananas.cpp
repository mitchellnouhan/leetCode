class Solution {
public:
    long int calcHours(vector<int> piles, int speed){
        long int hours = 0;
        for(int pile: piles){
            hours += pile / speed;
            if(pile % speed)
                hours++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //int res = 0;
        int l = 1;
        int r = 1;
        for(int pile: piles)
            r = max(r, pile);
        //
        while (l <= r){
            int m = l + (r - l) / 2;
            long int hours = calcHours(piles, m);
            //too slow! deal breaker
            if(hours > h)
                l = m + 1;
            //too fast or the right number of hours BUT can koko eat slower??
            else
                r = m - 1;
        }
        return l;
    }
};
