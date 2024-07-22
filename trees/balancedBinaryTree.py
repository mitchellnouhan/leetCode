# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.res = True

    def dfs(self, root: Optional[TreeNode]) -> int:
        if not root: return 0
        leftLen, rightLen  = self.dfs(root.left), self.dfs(root.right)
        self.res &= (abs(leftLen - rightLen) <= 1)
        return 1 + max(leftLen, rightLen)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        self.dfs(root)
        return self.res