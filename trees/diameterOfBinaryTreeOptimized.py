#key to optimized solution: calculate and update the diameter of the tree while you're finding the max depth
#as the recursive function is digging down into the tree to calculate the depth, the diameter will be updated 


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.diameter = 0

    def updateDiameterCalcDepth(self, root):
        if root is None:
            return 0
        
        leftDepth = self.updateDiameterCalcDepth(root.left)
        rightDepth = self.updateDiameterCalcDepth(root.right)
        currentRootDiameter = leftDepth + rightDepth
        self.diameter = max(self.diameter, currentRootDiameter)

        return 1 + max(leftDepth, rightDepth)

    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.updateDiameterCalcDepth(root)
        return self.diameter