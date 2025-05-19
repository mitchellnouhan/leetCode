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
    void dfs(TreeNode* root, int targetSum, int curSum, bool* res){
        //base cases
        //null node, return
        if(*res || !root){
            return;
        }
        //if leaf node, check if curPathSum == targetSum
        if(!root -> left && !root -> right){
            *res = (curSum + root -> val == targetSum);
            return;
        }

        //recursive cases
        dfs(root -> left, targetSum, curSum + root -> val, res);
        dfs(root -> right, targetSum, curSum + root -> val, res);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        int curSum = 0;
        dfs(root, targetSum, curSum, &res);
        return res;
    }
};