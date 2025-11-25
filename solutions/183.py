class Solution:
    def climbStairs(self, n: int) -> int:
        if n < 2:
            return n

        values = [0 for _ in range(n + 1)]
        values[1] = 1
        values[2] = 2

        for i in range(3, n + 1):
            values[i] = values[i - 1] + values[i - 2]

        return values[n]
