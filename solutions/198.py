# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        cur_head = head
        while cur_head and cur_head.next:
            head = head.next
            cur_head = cur_head.next.next

            if cur_head is head:
                return True

        return False
