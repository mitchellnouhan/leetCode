# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Key is to return local min and local max, & handle None
class Solution:
    def __init__(self):
        self.res = True
    
    def dfs(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return [None, None]

        left, right = self.dfs(root.left), self.dfs(root.right)
        
        if left[1] is None and right[0] is None:
            return [root.val, root.val]
        elif left[1] is not None and right[0] is None:
            self.res &= root.val > left[1]
            return [left[0], max(left[1], root.val)]
        elif left[1] is None and right[0] is not None:
            self.res &= root.val < right[0]
            return [min(root.val, right[0]), right[1]]
        self.res &= root.val > left[1] and root.val < right[0]
        return [left[0], right[1]]

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        self.dfs(root)
        return self.res