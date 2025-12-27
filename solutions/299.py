class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        res = 0
        min_x = m
        min_y = n

        for i in range(len(ops)):
            min_x = min(min_x, ops[i][0])
            min_y = min(min_y, ops[i][1])

        return min_x * min_y
