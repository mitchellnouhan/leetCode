class Solution {
public:
    int trap(vector<int>& height) {
        //for each height we want to calc how much water is trapped
        //for each height, we find the maxleft and maxright height
        //then we cal. max((min(maxLeft,maxRight) - height),0)
        //iterate
        //at the end of the day, for every height
        //create maxLeft and maxRight vectors
        int res = 0;
        vector<int> maxHeightLeft(height.size(),0);
        int maxLeft = 0;
        for(int i = 0; i < height.size(); i++){
            maxHeightLeft[i] = maxLeft;
            maxLeft = max(maxLeft, height[i]);
        }
        vector<int> maxHeightRight(height.size(),0);
        int maxRight = 0;
        for(int i = height.size() - 1; i >= 0; i--){
            maxHeightRight[i] = maxRight;
            maxRight = max(maxRight, height[i]);
        }
        for(int i = 0; i < height.size(); i++){
            res += max(0, min(maxHeightLeft[i], maxHeightRight[i]) - height[i]);
        }
        return res;
    }
};
