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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()){
            TreeNode* cur = s.top();
            s.pop();
            swap(cur -> left, cur -> right);
            if(cur -> left) s.push(cur -> left);
            if(cur -> right) s.push(cur -> right);
        }
        return root;
    }
};
