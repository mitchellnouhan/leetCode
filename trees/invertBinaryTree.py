# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        #if TreeNode is a leaf node, return 
        if root is None or (root.left is None and root.right is None):
            return root
        #invert left subtree, invert right subtree, then swap left & right
        self.invertTree(root.left)
        self.invertTree(root.right)
        root.left, root.right = root.right, root.left
        return root