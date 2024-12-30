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
    int res;
    int count;
    Solution(){
        res = 0;
        count = 0;
    }

    void dfs(TreeNode* root, int k){
        if(!root) return;

        dfs(root -> left, k);
        count++;
        if (count == k) res = root -> val;
        dfs(root -> right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
