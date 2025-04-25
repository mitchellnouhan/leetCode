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
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        if(root){
            q.push(root);
        }
        

        while (q.size()){
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* tmp = cur -> left;
            cur -> left = cur -> right;
            cur -> right = tmp;
            if(cur -> left){
                q.push(cur -> left);
            }
            if(cur -> right){
                q.push(cur -> right);
            }
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        bfs(root);
        return root;
    }
};
