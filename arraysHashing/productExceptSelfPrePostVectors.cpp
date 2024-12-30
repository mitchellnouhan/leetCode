class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // run though nums to create preduct and postduct vectors
        // preduct vector
        vector<int> preduct(nums.size(),1);
        preduct[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            preduct[i] = nums[i] * preduct[i - 1];

        // postduct vector
        vector<int> postduct(nums.size(),1);
        postduct[nums.size() - 1] = nums[nums.size() - 1];
        for(int i = nums.size() - 2; i >= 0; i--)
            postduct[i] = nums[i] * postduct[i + 1];

        // go through and fill in res
        vector<int> res(nums.size(),1);
        for(int i = 0; i < nums.size(); i++){
            int pre = 1;
            int post = 1;
            if(i == 0)
                post = postduct[i + 1];
            else if(i == nums.size() - 1)
                pre = preduct[i - 1];
            else{
                pre = preduct[i - 1];
                post = postduct[i + 1];
            }
            res[i] = pre * post;
        }
        return res;
    }
};
