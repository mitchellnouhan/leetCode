# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.curDepth = 0
        self.res = None
    
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
        #base case
        if not root:
            self.curDepth -= 1
            return

        #append root to res
        self.res[self.curDepth] = root.val
        #increment depth by 1
        self.curDepth += 1
        #go into left subtree
        self.preOrderTraversal(root.left)
        #increment depth by 1
        self.curDepth += 1
        #go into right subtree
        self.preOrderTraversal(root.right)
        #decrement depth by 1 before returning
        self.curDepth -= 1
        return
    
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.res = [0] * self.maxDepth(root)
        self.preOrderTraversal(root)
        return self.res