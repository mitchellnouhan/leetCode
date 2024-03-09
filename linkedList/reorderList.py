# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # split list in half
        tail, fast, slow = None, head, head
        while fast:
            tail, fast, slow = slow, fast.next, slow.next
            fast = fast.next if fast else fast
        tail.next = None
        # everse second half list
        prev = None
        while slow:
            tmp = slow.next
            slow.next = prev
            prev, slow = slow, tmp
        # merge lists 
        h1, h2 = head, prev
        while h1 and h2:
            tmp1, tmp2 = h1.next, h2.next
            h1.next, h1 = h2, tmp1
            h2.next, h2 = h1, tmp2  