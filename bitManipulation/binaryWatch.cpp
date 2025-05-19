class Solution {
public:
    int start = 0;
    int end = (1 << 11);

    int numberOfSetBits(int n){
        int res = 0;
        for(int i = 0; i < 11; i++){
            int mask = 1 << i;
            if(n & mask){
                res++;
            }
        }
        return res;
    }

    vector<int> grabNumbersWithNSetBits(int n){
        vector<int> res;
        for(int i = start; i < end; i++){
            if(numberOfSetBits(i) == n){
                res.push_back(i);
            }
        }
        return res;
    }

    void calcMinHour(int bf, int* minute, int* hour){
        // calc minute and hour
        for(int i = 0; i < 11; i++){
            if(0 <= i && i <= 5 && (bf & (1 << i))){
                *minute |= (1 << i);
            }
            else if(i > 5 && (bf & (1 << i))){
                *hour |= (1 << (i - 6));
            }
        }
    }

    bool validatebf(int* minute, int* hour){
        // check for invalid hour
        // check for invalid minute
        return (*hour > 11 || *minute > 59) ? false : true;
    }

    string bf_to_string(int* minute, int* hour){
        string res = "";
        string hour_string = to_string(*hour);
        string minute_string = to_string(*minute);
        res += hour_string;
        res += ':';
        if(*minute < 10){
            res += '0';
        }
        res += minute_string;
        return res;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        /*
        -get numbers between [0, 2 ** 11) for <turnedOn> number of set bits
        -calc corresponding hour and minute values
        -go thru calculated hour and minute for validity
        -if valid, translate to string time
        -push to the back of the result vector of strings
        -return 
        */

        vector<string> res;
        vector<int> bfs = grabNumbersWithNSetBits(turnedOn);
        for(int bf: bfs){
            int hour = 0;
            int minute = 0;
            calcMinHour(bf, &minute, &hour);
            if(validatebf(&minute, &hour)){
                res.push_back(bf_to_string(&minute, &hour));
            }
        }
        return res;
    }
};
