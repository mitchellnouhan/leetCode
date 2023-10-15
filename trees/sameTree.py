# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        #base cases
        if not p and not q:
            return True
        elif (p and not q) or (not p and q):
            return False     
        #same tree if root val's are the same, left subtree is the same, and right subtree is the same
        return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)