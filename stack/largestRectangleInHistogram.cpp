class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<pair<int, int>> stack;
        for(int i = 0; i < heights.size(); i++){
            int index = i;
            while(!stack.empty() && heights[i] < stack.top().second){
                int cur_i = stack.top().first;
                int cur_h = stack.top().second;
                int cur_area = cur_h * (i - cur_i);
                res = max(res, cur_area);
                index = cur_i;
                stack.pop();
            }
            stack.push({index, heights[i]});
        }
        while(!stack.empty()){
            int cur_i = stack.top().first;
            int cur_h = stack.top().second;
            int cur_area = cur_h * (heights.size() - cur_i);
            res = max(cur_area, res);
            stack.pop();
        }
        return res;
    }
};
