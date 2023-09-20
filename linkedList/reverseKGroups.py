#Did this one myself w/o peaking at the solutions. A hard LL problem. Was getting 5th percentile running time, thought it was my algoritm
#HOWEVER, it was because I was running my print list function every iteration of the while loop, after removing, shit looks good asl runtime and space wise
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def printList(self, head):
        print('PRINTING LIST')
        dummy = head
        while dummy:
            print(str(dummy.val) + ','),
            dummy = dummy.next
        print('\n')
    
    def removeKGroup(self, head, k):
        #iterate thru k nodes, sever, return groupHead and groupNext
        count = 1
        dummy = head
        for i in range(k-1):
            dummy = dummy.next
            if dummy is None:
                return [None, None]
        #at this point, there is enough nodes to form a group of size K
        #return groupHead and groupNext
        groupHead = head
        #sever
        groupNext = dummy.next
        dummy.next = None
        return [groupHead, groupNext]
        
    def reverseGroup(self, head):
        newTail = head
        prev = None
        cur = head
        forw = cur.next
        while forw:
            #update .next pointers
            cur.next = prev
            #update ListNode pointers
            prev = cur
            cur = forw
            forw = forw.next
        #return head & tail
        cur.next = prev
        newHead = cur
        return [newHead, newTail]    
        
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        #base case
        if k == 1:
            return head

        cur = head
        #init to dummy ListNode
        newLLHead = ListNode()
        groupPrev = ListNode()
        groupPrev.next = cur
        #iterating through the list, we want to:
        while cur:
            #removeGroupOfSizeK from LL
            #keep track of groupPrev, groupNext before calling helper function 
            [groupHead,groupNext] = self.removeKGroup(cur, k)
            if groupHead is None:
                #that means we do not have k nodes left in LL to reverse, exit
                return newLLHead.next
            #reverseGroupOfSizeK 
            #create a reverse LL helper function that returns new head & tail
            [newHead, newTail] = self.reverseGroup(groupHead)
            if cur == head:
                newLLHead.next = newHead
            #add reversed group back to LL
            #update next pointers
            groupPrev.next = newHead
            newTail.next = groupNext
            #update group ListNode variables
            groupPrev = newTail
            cur = groupNext
        return newLLHead.next