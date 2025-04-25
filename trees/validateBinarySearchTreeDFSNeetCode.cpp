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
 INVERT!! 
 
 */

class Solution {
public:
    bool dfs(TreeNode* root, long local_min, long local_max){
        if(!root) return true;

        if(!(local_min < (long)root -> val && (long)root -> val < local_max)) return false;

        return dfs(root -> left, local_min, root -> val) && dfs(root -> right, root -> val, local_max);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
