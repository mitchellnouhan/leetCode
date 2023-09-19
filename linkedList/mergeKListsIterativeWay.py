# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):

    def mergeLists(self, l1, l2):
        if l1 is None and l2 is None:
            return None
        elif l1 and l2 is None:
            return l1
        elif l1 is None and l2:
            return l2
        
        dummyHead = ListNode()
        tmp = dummyHead
        while l1 and l2:
            if l1.val < l2.val:
                tmp.next = l1
                l1 = l1.next
            else:
                tmp.next = l2
                l2 = l2.next
            tmp = tmp.next
        if l1:
            tmp.next = l1
        elif l2:
            tmp.next = l2
        return dummyHead.next

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return None
       
        while len(lists) > 1:
            curLen = len(lists)
            newLists = []
            for i in range(0, curLen, 2):
                l1 = lists[i]
                if (i + 1) > curLen - 1:
                    l2 = None
                else:
                    l2 = lists[i + 1]

                newLists.append(self.mergeLists(l1,l2))
            lists = newLists
        return lists[0]