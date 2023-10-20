# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.maxPath = []
        self.maxPathEmptyFlag = True

    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        #base case
        if not root:
            return 0
        
        #handle root
        rootIsGood = 0
        if self.maxPathEmptyFlag or root.val >= self.maxPath[-1]:
            if self.maxPathEmptyFlag:
                self.maxPathEmptyFlag = False
            rootIsGood = 1
            self.maxPath.append(root.val)

        #handle left subtree
        leftGoodNodes = self.goodNodes(root.left)

        #handle right subtree
        rightGoodNodes = self.goodNodes(root.right)

        #cleanup root before returning
        if root.val == self.maxPath[-1]:
            self.maxPath.pop()

        return rootIsGood + leftGoodNodes + rightGoodNodes