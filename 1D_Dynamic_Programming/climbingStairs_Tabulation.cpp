class Solution {
public:
    int climbStairs(int n) {
        vector<int> tab = {0, 1};
        int i = 2;
        while (i < n + 1){
            tab.push_back(tab[i - 1] + tab[i - 2]);
            i++;
        }
        return tab[i - 1] + tab[i - 2]; 
    }
};
