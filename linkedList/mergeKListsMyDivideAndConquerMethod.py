#my stab at a homemade, no peaking recursive divide and conquor method, end result wasn't very optimal, 21% runtime:/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoListGroups(self, group1, group2):
        len1 = len(group1)
        len2 = len(group2)

        if len1 == 0 and len2 == 1:
            return group2
        elif len1 == 1 and len2 == 0:
            return group1
        elif len1 == 1 and len2 == 1:
            #merge the two lists 
            dummyHead = ListNode()
            cur = dummyHead
            l1 = group1[0]
            l2 = group2[0]
            while l1 and l2:
                if l1.val < l2.val:
                    cur.next = ListNode(l1.val)
                    l1 = l1.next
                else:
                    cur.next = ListNode(l2.val)
                    l2 = l2.next
                cur = cur.next
            if l1:
                cur.next = l1
            elif l2:
                cur.next = l2
            holder = []
            holder.append(dummyHead.next)
            return holder

        mid1 = len1 // 2
        mid2 = len2 // 2
        return self.mergeTwoListGroups(self.mergeTwoListGroups(group1[:mid1],group1[mid1:]), self.mergeTwoListGroups(group2[:mid2],group2[mid2:]))
        
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        listNum = len(lists)
        if listNum == 0:
            return None
        elif listNum == 1:
            return lists[0]
        midPoint = listNum // 2
        group1 = lists[:midPoint]
        group2 = lists[midPoint:]
        return self.mergeTwoListGroups(group1,group2)[0]
        