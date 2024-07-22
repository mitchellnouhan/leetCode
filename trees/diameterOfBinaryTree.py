# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.res = 0

    def dfs(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        leftLen, rightLen = self.dfs(root.left), self.dfs(root.right)    
        self.res = max(self.res, leftLen + rightLen)
        return 1 + max(leftLen, rightLen)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res