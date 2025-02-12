# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        num = ""

        node = head
        while node != None:
            num += f"{node.val}"
            node = node.next

        num = num[::-1]
        res = None
        tmp = None
        tmp2 = 0
        for v in num:
            x = int(v) * 2
            res = ListNode((x % 10) + tmp2, tmp)
            tmp = res
            tmp2 = x // 10

        if tmp2 != 0:
            tmp = res
            res = ListNode(tmp2, tmp)

        return res