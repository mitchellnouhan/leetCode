# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.res = 0
        self.arr = []
        self.curInd = 0

    def inOrderTrav(self, root, k):
        if not root or self.curInd == k:
            return 
        
        self.inOrderTrav(root.left, k)

        self.arr.append(root.val)
        self.curInd += 1
        if self.curInd == k:
            self.res = self.arr[self.curInd - 1]

        self.inOrderTrav(root.right, k)

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.inOrderTrav(root, k)
        return self.res