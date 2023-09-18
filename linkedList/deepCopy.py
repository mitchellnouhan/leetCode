"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        #we're going to use a hash map! 
        #go through the list once and create the map
        #go through the map and fill in the map Nodes' next and random pointers
        hashMap = {None: None}
        cur = head
        while cur:
            hashMap[cur] = Node(cur.val)
            cur = cur.next
        
        cur = head
        while cur:
            hashMap[cur].next = hashMap[cur.next]
            hashMap[cur].random = hashMap[cur.random]
            cur = cur.next
        
        return hashMap[head]