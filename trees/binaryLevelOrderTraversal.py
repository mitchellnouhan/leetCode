# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.res = defaultdict(list)

    def dfs(self, root: Optional[TreeNode], level: int):
        if not root: return
        self.res[level].append(root.val)
        self.dfs(root.left, level + 1)
        self.dfs(root.right, level + 1)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.dfs(root, 0)
        return list(self.res.values())