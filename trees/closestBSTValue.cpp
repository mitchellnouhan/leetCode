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
    double min_diff = -1;
    int closest = -1;

    void dfs(TreeNode* root, double target){
        if(!root){
            return;
        }

        dfs(root -> left, target);        
        double cur_diff = abs(root -> val - target);
        if(min_diff == -1 || cur_diff < min_diff || (cur_diff == min_diff && root -> val < closest)){
            min_diff = cur_diff;
            closest = root -> val;
        }
        dfs(root -> right, target);
    }

    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return closest;
    }
};