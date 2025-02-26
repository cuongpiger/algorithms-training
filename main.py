import sys
from queue import PriorityQueue
from typing import List


def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


def solve(nums: List) -> int:
    greedy = [0] * (len(nums) + 1)
    for i in range(len(nums)):
        greedy[i + 1] = greedy[i] + nums[i]
        
    i, j, res = 0, 1, 0
    for i in range(len(nums)):
        for j in range(i + 1, len(nums) + 1):
            res = max(res, greedy[j] - greedy[i])
            
    return res

                
# FILE_IO()
res = solve([-7,-1,0,-2,1,3,8,-2,-6,-1,-10,-6,-6,8,-4,-9,-4,1,4,-9])
print(res)