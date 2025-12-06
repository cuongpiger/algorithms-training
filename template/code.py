# Definition for singly-linked list.
from typing import Optional
from typing import List

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        front, prev = 0, 0
        multi = 1

        while not head:
            front = front * 10 + head.val
            prev = head.val * multi + prev
            multi = multi * 10
            head = head.next

        return int(front) == int(prev)


head = ListNode(1)
head.next = ListNode(2)

sol = Solution()
print(sol.isPalindrome(head))  # Output: False
