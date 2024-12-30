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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        
        int res = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        while(!s.empty()){
            pair<TreeNode*, int> cur = s.top();
            s.pop();
            
            TreeNode* cur_node = cur.first;
            int cur_depth = cur.second;
            res = max(res, cur_depth);
            if(cur_node -> right) s.push({cur_node -> right, cur_depth + 1});
            if(cur_node -> left) s.push({cur_node -> left, cur_depth + 1});
        }
        return res;
    }
};
