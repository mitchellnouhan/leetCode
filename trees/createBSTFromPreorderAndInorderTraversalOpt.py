# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        #base case
        if not preorder:
            return None

        #handle root assignment with preorder
        root = TreeNode(val=preorder[0])

        #find root index in inorder
        mid = inorder.index(preorder[0])

        #assign & handle left side
        root.left = self.buildTree(preorder[1:mid + 1], inorder[:mid])

        #assign & handle right side
        root.right = self.buildTree(preorder[mid + 1:], inorder[mid + 1:])
        
        #return tree
        return root