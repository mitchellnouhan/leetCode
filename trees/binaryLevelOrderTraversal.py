# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.res = []
        self.curDepth = 0

    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    def preOrderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: None
        """
        #base case: root is None
        if not root:
            self.curDepth -= 1
            return 
        
        #add root to res
        self.res[self.curDepth].append(root.val)
        #increment curDepth by 1
        self.curDepth += 1
        #add left subtree
        self.preOrderTraversal(root.left)
        #increment curDepth by 1
        self.curDepth += 1
        #add right subtree
        self.preOrderTraversal(root.right)
        #decrement curDepth by 1 before returning
        self.curDepth -= 1
        return 

    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        for i in range(self.maxDepth(root)):
            self.res.append([])

        self.preOrderTraversal(root)
        return self.res