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
    void dfs(TreeNode* root, bool left_node, int* res){
        //base cases:
        if(!root){
            return;
        }
        
        if(!root -> left && !root -> right && left_node){
            *res += root -> val;
        }

        //recursive cases:
        dfs(root -> left, true, res);
        dfs(root -> right, false, res);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        bool left_node = false;
        dfs(root, left_node, &res);
        return res;
    }
};