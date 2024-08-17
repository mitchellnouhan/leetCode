# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.res = 0

    def dfs(self, root: TreeNode, curMax: int):
        if not root: return

        if root.val >= curMax:
            self.res += 1
            curMax = root.val
        
        self.dfs(root.left, curMax)
        self.dfs(root.right, curMax)

    def goodNodes(self, root: TreeNode) -> int:
        self.dfs(root, root.val)
        return self.res
        