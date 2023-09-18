#I watched the neetcode video on how to implement the LRU cache on papar but did the coding implementation myself w/o peaking.
#first time doing OOO coding from scratch and am proud of myself as this worked on the firt try
# This LRU cache implementation uses a hash map and double LL for O(1) get and put functions

class Node(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None
    
class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        #init maxCap, curCap, hashTable and double LL left & right dummy nodes
        self.maxCap = capacity
        self.curCap = 0
        self.hash = {}
        self.left = Node(0,0)
        self.right = Node(0,0)
        self.left.next = self.right
        self.right.prev = self.left

    def removeNode(self, node):
        #create holder node vars for node's prev and next nodes
        prevNode = node.prev
        nextNode = node.next
        #update nodes pointers to point to None
        node.prev = None
        node.next = None
        #update prevNode and nextNode pointers
        prevNode.next = nextNode
        nextNode.prev = prevNode
        #return node for either freeing or inserting
        return node

    def insertNode(self, node):
        #insert Node @ righ most end of LL 
        #create holder vars for right node of LRU cache and right's prev
        rightNode = self.right
        behindRightNode = rightNode.prev
        #update rightNode and behindRightNode to point to node
        rightNode.prev = node
        behindRightNode.next = node
        #update node's prev and next pointers
        node.next = rightNode
        node.prev = behindRightNode

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        #check to see if key is in hash
        if key in self.hash:
            #grab the value
            val = self.hash[key].value
            #move the Nodes to right of the list
            node = self.removeNode(self.hash[key])
            self.insertNode(node)
            #return val
            return val
        #if not, return -1
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        # check to see if key exists
        if key in self.hash:
            #update its value
            self.hash[key].value = value
            #move node to right of the LL
            node = self.removeNode(self.hash[key])
            self.insertNode(node)
            return
        #if key doesn't exist, add it
        if self.curCap >= self.maxCap:
            #if the capacity is met, we evict LRU node,
            lruNode = self.removeNode(self.left.next)
            #update hash table
            del self.hash[lruNode.key]
            #add new node
            newNode = Node(key, value)
            self.hash[key] = newNode
            self.insertNode(newNode)
        else:
            #if max capacity isn't met, just add it to cache
            node = Node(key, value)
            self.hash[key] = node
            self.insertNode(node)
            self.curCap += 1
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)