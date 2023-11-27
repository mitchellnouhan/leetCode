# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def validBST(self, root):
        """
        :type root: TreeNode       
        :rtype: bool, int, int
        """
        #base case
        if not root:
            #returns validBST, treeMin, treeMax
            return (True, float('inf'), float('-inf'))

        #check if left subtree is valid
        left = self.validBST(root.left)
        leftBST = left[0]
        leftMin = left[1]
        leftMax = left[2]

        #check if right subtree is valid
        right = self.validBST(root.right)
        rightBST = right[0]
        rightMin = right[1]
        rightMax = right[2]
        
        #update leftMax
        treeMin = min(leftMin, root.val, rightMin)
        #update rightMin
        treeMax  = max(leftMax, root.val, rightMax)
        
        return (leftBST and rightBST and root.val > leftMax and root.val < rightMin, treeMin, treeMax)
      
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """ 
        return self.validBST(root)[0]