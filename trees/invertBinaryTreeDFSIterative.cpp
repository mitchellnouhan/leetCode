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
    void dfs_iterative(TreeNode* root){
        deque<TreeNode*> q;
        if(root){
            q.push_back(root);
        }
        

        while (q.size()){
            TreeNode* cur = q.back();
            q.pop_back();
            TreeNode* tmp = cur -> left;
            cur -> left = cur -> right;
            cur -> right = tmp;
            if(cur -> left){
                q.push_back(cur -> left);
            }
            if(cur -> right){
                q.push_back(cur -> right);
            }
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        dfs_iterative(root);
        return root;
    }
};
