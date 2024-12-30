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
    void bfs(TreeNode* root, vector<vector<int>>& res){
        if(!root){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int cur_size = q.size();
            vector<int> level;
            for(int i = 0; i < cur_size; i++){
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur -> val);
                if(cur -> left){
                    q.push(cur -> left);
                }
                if(cur -> right){
                    q.push(cur -> right);
                }
            }
            res.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        bfs(root, res);
        return res;
    }
};
