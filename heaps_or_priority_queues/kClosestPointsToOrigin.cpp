class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const vector<int>& p1, const vector<int>& p2){
            return p1[0] * p1[0] + p1[1] * p1[1] > p2[0] * p2[0] + p2[1] * p2[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> min_heap(compare);
        for(const auto& point: points){
            min_heap.push(point);
        }

        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            res.push_back(min_heap.top());
            min_heap.pop();
        }
        return res;
    }
};
