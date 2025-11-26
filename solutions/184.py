from typing import Optional

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        unique_node = head
        cur_node = head

        while cur_node is not None:
            if cur_node.val != unique_node.val:
                unique_node.next = cur_node
                unique_node = cur_node
            else:
                cur_node = cur_node.next

        if unique_node is not None and unique_node.next is not None:
            if unique_node.val == unique_node.next.val:
                unique_node.next = None

        return head
