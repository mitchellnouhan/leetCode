# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head.next if head else None
        while fast and fast != head:
            head = head.next
            fast = fast.next
            fast = fast.next if fast else fast
        return True if fast else False