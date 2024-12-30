class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxLeft = height[l];
        int maxRight = height[r];
        while(l < r){
            if (maxLeft < maxRight){
                res += max(maxLeft - height[++l], 0);
                maxLeft = max(maxLeft, height[l]);
            }
            else{
                res += max(maxRight - height[--r], 0);
                maxRight = max(maxRight, height[r]);
            }
        }
        return res;
    }
};
