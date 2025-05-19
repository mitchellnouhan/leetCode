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
    void get_depth(TreeNode* root, int cur_depth, pair<int, TreeNode*>& x_i, pair<int, TreeNode*>& y_i, int x, int y){
        if(!root){
            return;
        }
        get_depth(root -> left, cur_depth + 1, x_i, y_i, x, y);
        if(root -> val == x){
            x_i.first = cur_depth;
        }
        if(root -> val == y){
            y_i.first = cur_depth;
        }
        get_depth(root -> right, cur_depth + 1, x_i, y_i, x, y);
    }

    void get_parent(TreeNode* root, TreeNode* cur_parent, pair<int, TreeNode*>& x_i, pair<int, TreeNode*>& y_i, int x, int y){
        if(!root){
            return;
        }
        get_parent(root -> left, root, x_i, y_i, x, y);
        if(root -> val == x){
            x_i.second = cur_parent;
        }
        if(root -> val == y){
            y_i.second = cur_parent;
        }
        get_parent(root -> right, root, x_i, y_i, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> x_depth_parent;
        pair<int, TreeNode*> y_depth_parent;
        get_depth(root, 0, x_depth_parent, y_depth_parent, x, y);
        get_parent(root, nullptr, x_depth_parent, y_depth_parent, x, y);
        return (x_depth_parent.first == y_depth_parent.first && x_depth_parent.second != y_depth_parent.second);
    }
};