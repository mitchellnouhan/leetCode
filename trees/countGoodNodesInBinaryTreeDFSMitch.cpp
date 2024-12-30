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

class Solution {
public:
    void dfs(TreeNode* root, int& res, int cur_max){
        if(!root) return;

        int new_max = max(cur_max, root -> val);

        if(root -> val >= new_max) res++;

        dfs(root -> left, res, new_max);
        dfs(root -> right, res, new_max);
    }

    int goodNodes(TreeNode* root) {
        int res = 0;
        int cur_max = -101;
        dfs(root, res, cur_max);
        return res;
    }
};
