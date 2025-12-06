# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            return True

        slow = head
        fast = head
        while (fast and fast.next) is not None:
            slow = slow.next
            fast = fast.next.next

        prev = None
        while slow is not None:
            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node

        first = prev
        second = head
        while (first and second) is not None:
            if first.val != second.val:
                return False

            first = first.next
            second = second.next

        return True
