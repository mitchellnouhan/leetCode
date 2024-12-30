/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
                4
            /       \
           2         5
         /.  \
        1     3
*/
class Solution {
public:
    pair<bool, pair<long, long>> dfs(TreeNode* root){
        // base case
        if(!root) return {true, {LONG_MAX, LONG_MIN}};

        // recursive case
        pair<bool, pair<long, long>> l = dfs(root -> left);
        bool l_valid = l.first;
        long l_min = l.second.first;
        long l_max = l.second.second;

        pair<bool, pair<long, long>> r = dfs(root -> right);
        bool r_valid = r.first;
        long r_min = r.second.first;
        long r_max = r.second.second;

        long local_min = min(min((long)root -> val, l_min), r_min);
        long local_max = max(max((long)root -> val, l_max), r_max);
        bool cur_valid = (root -> val > l_max) && (root -> val < r_min);

        bool res_valid = l_valid && r_valid && cur_valid;
        pair<bool, pair<long, long>> res = {res_valid, {local_min, local_max}};
        
        return res;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root).first;
    }
};
