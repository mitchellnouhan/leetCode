# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):    
    def isSameTree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        #needs to be same leftSub tree, and same rightSub tree
        if (root and not subRoot) or (not root and subRoot):
            return False
        elif not root and not subRoot:
            return True
        elif root.val != subRoot.val:
            return False
        
        return self.isSameTree(root.left, subRoot.left) and self.isSameTree(root.right, subRoot.right)
        
    def isSubtree(self, root, subRoot):
        """
        :type root: TreeNode
        :type subRoot: TreeNode
        :rtype: bool
        """
        if root is None:
            return False

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot) or self.isSameTree(root, subRoot)   