from queue import PriorityQueue
import sys


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


# def solve():
#     n = int(input())
#     pq = PriorityQueue()
#     pqr = PriorityQueue()
    
#     for _ in range(n):
#         line = input()
        
#         if line[0] == '1':
#             x = int(line.split()[1])
#             pq.put(x)
#         elif line[0] == '2':
#             x = int(line.split()[1])
#             pqr.put(x)
#         else:
#             while not pqr.empty() and pq.queue[0] == pqr.queue[0]:
#                 pq.get()
#                 pqr.get()
        
#             print(pq.queue[0])
                
# # FILE_IO()
# solve()

def formula(prim_value: int, len_: int):
    len_ = min(len_, prim_value)
    sub_value = max(prim_value - len_ + 1, 0)
    return len_*(sub_value + prim_value) // 2


def maxValue(n: int, index: int, maxSum: int) -> int:
    # res = n - 1
    # for x in range(n - 1, -1, -1):
    #     prim_value = x - 1
    #     sum_left = formula(prim_value, index)
    #     sum_right = formula(prim_value, n - 1 - index)

    #     print(f"with x = {x} then sum_left = {sum_left} and sum_right = {sum_right}")
    #     if x + sum_left + sum_right > maxSum:
    #         continue

    #     res = x
    #     break

    # return res

    left = 1
    right = maxSum
    mid = (left + right) // 2
    res = 1
    while left <= right:
        prim_value = mid - 1
        sum_left = formula(prim_value, index)
        sum_right = formula(prim_value, n - 1 - index)
        tmp = mid + sum_left + sum_right 
        print(f"with mid = {mid}, left is {left} and right is {right} then sum_left = {sum_left} and sum_right = {sum_right} and tmp = {tmp}")

        if tmp > maxSum:
            right = mid
        else:
            left = mid

        res = max(res, mid)
        tmp = (left + right) // 2
        if tmp == mid:
            break
        else:
            mid = tmp

    return res



print(maxValue(6, 1, 10))

# with mid = 3, left is 3 and right is 4 then sum_left = 2 and sum_right = 3 and tmp = 8