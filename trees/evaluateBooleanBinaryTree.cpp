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
    bool evaluateTree(TreeNode* root) {
        if(!root -> left && !root -> right){
            return (bool)(root -> val);
        }

        bool operand_left = evaluateTree(root -> left);
        bool operand_right = evaluateTree(root -> right);
        return (root -> val == 2) ? (operand_left || operand_right) : (operand_left && operand_right);
    }
};