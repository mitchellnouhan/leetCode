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
    void dfs(TreeNode* root, vector<string>& res, string cur_path){
        //base cases
        //null, return
        if(!root){
            return;
        }
        //leaf, add root to cur_path, then push cur_path to res, return
        if(!root -> left && !root -> right){
            res.push_back(cur_path + to_string(root -> val));
            return;
        }

        //recursive cases
        //left
        dfs(root -> left, res, cur_path + (to_string(root -> val) + "->"));
        //right
        dfs(root -> right, res, cur_path + (to_string(root -> val) + "->"));
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string cur = "";
        dfs(root, res, cur);
        return res;
    }
};