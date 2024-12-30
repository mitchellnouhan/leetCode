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
    pair<bool, int> dfs(TreeNode* root){
        if(!root) return {true, 0};

        pair<bool, int> l = dfs(root -> left);
        pair<bool, int> r = dfs(root -> right);

        bool cur_balance = l.first && r.first && (abs(l.second - r.second) < 2);
        int cur_height = 1 + max(l.second, r.second);

        return {cur_balance, cur_height};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
