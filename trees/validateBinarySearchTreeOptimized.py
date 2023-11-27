# Optimized solution, key is to "array-ify" the tree in question, then make sure it's sorted
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inOrderTraversal(self, root, arr):
        if not root:
            return
        
        self.inOrderTraversal(root.left, arr)
        arr.append(root.val)
        self.inOrderTraversal(root.right, arr)

    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        #array-ify
        arr = []
        self.inOrderTraversal(root, arr)

        #check is array is sorted
        for i in range(0,len(arr) - 1):
            if arr[i] >= arr[i + 1]:
                return False
        return True 