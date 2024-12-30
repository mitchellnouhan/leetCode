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
    void bfs(TreeNode* root, int& res){
        if(!root) return;

        int cur_max = -101;

        queue<pair<TreeNode*, int>> q;
        q.push({root, cur_max});

        while(!q.empty()){
            TreeNode* cur_t = q.front().first;
            int cur_m = q.front().second;
            q.pop();

            if(cur_t -> val >= cur_m) res++;

            if(cur_t -> left) q.push({cur_t -> left, max(cur_t -> val, cur_m)});
            if(cur_t -> right) q.push({cur_t -> right, max(cur_t -> val, cur_m)}); 
        }
    }

    int goodNodes(TreeNode* root) {
       int res = 0;
       bfs(root, res);
       return res; 
    }
};
