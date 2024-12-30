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
        if (!root){
            return 0;
        }
        int res = 0;
        queue < TreeNode* > q;
        q.push(root);

        while(q.size()){
            res++;
            int cur_size = q.size();
            for(int i = 0; i < cur_size; i++){
                TreeNode * cur_node = q.front();
                q.pop();

                if(cur_node -> left){
                    q.push(cur_node -> left);
                }
                if(cur_node -> right){
                    q.push(cur_node -> right);
                }
            }
        }
        return res;
    }
};
