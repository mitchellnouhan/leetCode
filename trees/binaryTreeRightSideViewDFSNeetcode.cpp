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
    void dfs(TreeNode* root, vector<int>& res, int ind){
        if(!root) return;

        if(res.size() == ind) res.push_back(root -> val);
        
        dfs(root -> right, res, ind + 1);
        dfs(root -> left, res, ind + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};
