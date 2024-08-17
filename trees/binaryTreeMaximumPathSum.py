# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = -math.inf

    def dfs(self, root: Optional[TreeNode]):
        if not root: return 0

        leftLocalMax, rightLocalMax = self.dfs(root.left), self.dfs(root.right) 
        localMax = max(root.val, root.val + leftLocalMax, root.val + rightLocalMax)
        self.res = max(self.res, root.val + leftLocalMax + rightLocalMax, localMax)  
        return localMax

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res