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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root -> left, p, q);
        TreeNode* r = lowestCommonAncestor(root -> right, p, q);
        if(!l && !r){
            if(root -> val != p -> val && root -> val != q -> val){
                return nullptr;
            }
            else{
                return root;
            }
        }

        else if(!l && r){
            if(r -> val != p -> val && r -> val != q -> val){
                return r;
            }
            if(root -> val == p -> val || root -> val == q -> val){
                return root;
            }
            else{
                return r;
            }
        }
        else if(l && !r){
            if(l -> val != p -> val && l -> val != q -> val){
                return l;
            }
            if(root -> val == p -> val || root -> val == q -> val){
                return root;
            }
            else{
                return l;
            }          
        }
        return root;
    }
};
