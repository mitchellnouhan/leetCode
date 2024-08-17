# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    # Encodes a tree to a single string.
    def encodeVal(self, num: int) -> str:
        x = num
        res = ''
        num = abs(num)
        while num:
            res += chr((num % 10) + ord('0')) 
            num = num // 10
        if x < 0:
            res += '-'
        elif x == 0:
            res = '0'
        return res[-1::-1]

    def serialize(self, root: Optional[TreeNode]) -> str:
        if not root: return 'N'
        return self.encodeVal(root.val) + ',' + self.serialize(root.left) + ',' + self.serialize(root.right)
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]: 
        def dfs(data):
            nonlocal i
            if data[i] == 'N': 
                i += 1
                return None
            root = TreeNode(val=int(data[i]))
            i += 1
            root.left = dfs(data)
            root.right = dfs(data)
            return root
        i = 0
        data = data.split(',')
        return dfs(data)
