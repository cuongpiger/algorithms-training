class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        checker = n & 1
        n = n >> 1

        while n > 0 and n & 1 == 1 - checker:
            checker = 1 - checker
            n = n >> 1

        return n == 0
