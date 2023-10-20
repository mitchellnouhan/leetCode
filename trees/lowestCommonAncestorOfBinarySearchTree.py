# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.flag = False

    def checkVals(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: boolean
        """
        return root.val == p.val or root.val == q.val
    
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        #base case: leaf node
        if not root:
            return None
        elif (not root.left and not root.right):
            if self.checkVals(root, p, q):
                return root
            return None

        #assume function works
        #is LCA in left subtree?
        lLCA = self.lowestCommonAncestor(root.left, p, q)
        if lLCA and self.flag:
            return lLCA
        #is LCA in right subtree
        rLCA = self.lowestCommonAncestor(root.right, p, q)
        if rLCA and self.flag:
            return rLCA

        #is root the LCA?
        rootLCA = None
        if not lLCA and not rLCA:
            """
                    r == p or r == q
            """
            if self.checkVals(root, p, q):
                return root
            
        elif not lLCA and rLCA:
            """
                    r               r
                      \               \ 
                        p   or          q
            """
            if (rLCA.val == p.val and root.val == q.val) or (rLCA.val == q.val and root.val == p.val):
                self.flag = True
                rootLCA = root
            else:
                rootLCA = rLCA


        elif lLCA and not rLCA:
            """
                    r           r
                  /           /  
                p     or    q 
            """
            if (lLCA.val == p.val and root.val == q.val) or (lLCA.val == q.val and root.val == p.val):
                self.flag = True
                rootLCA = root
            else:
                rootLCA = lLCA
        
        elif (lLCA.val == p.val and rLCA.val == q.val) or (lLCA.val == q.val and rLCA.val == p.val):
            """
                    r               r      
                  /   \           /   \ 
                p       q   or  q       p
            """
            self.flag = True
            rootLCA = root
            
        return rootLCA