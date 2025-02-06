# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def fromListToNumber(l: Optional[ListNode]) -> int:
    str_num = ""
    next_ptr = l
    while next_ptr is not None:
        str_num = f"{next_ptr.val}" + str_num
        next_ptr = next_ptr.next

    return int(str_num)

def fromNumberToList(num: int) -> ListNode:
    res = []
    for digit in str(num):
        res.append(int(digit))

    list_node = ListNode(res[0], None)
    if len(res) > 1:
        for digit in res[1:]:
            old_node = list_node
            list_node = ListNode(digit, old_node)

    return list_node




class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num_a = fromListToNumber(l1)
        num_b = fromListToNumber(l2)
        product_sum = num_a + num_b
        return fromNumberToList(product_sum)