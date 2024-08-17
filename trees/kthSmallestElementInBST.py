# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = []

    def dfs(self, root: Optional[TreeNode]):
        if not root:
            return
        self.dfs(root.left)
        self.res.append(root.val)
        self.dfs(root.right)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.dfs(root)
        return self.res[k - 1]