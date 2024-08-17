# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.stack = []
        self.predex = 0
        self.index = 0

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        #is in oob
        if self.index == len(inorder):
            return None

        #is in ontop of the stack
        if len(self.stack) and inorder[self.index] == self.stack[-1]:
            self.stack.pop()
            self.index += 1
            return None

        #do root
        root = TreeNode(val=preorder[self.predex])
        self.stack.append(preorder[self.predex])
        self.predex += 1
        root.left = self.buildTree(preorder, inorder)
        root.right = self.buildTree(preorder, inorder)
        return root