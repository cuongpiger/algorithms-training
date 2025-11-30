class Solution:
    def isHappy(self, n: int) -> bool:
        mem = {}
        while n != 1 and not mem.get(n, False):
            mem[n] = True
            n = self._next_num(n)

        return n == 1

    def _next_num(self, n: int) -> int:
        nn = 0
        while n > 0:
            nn += (n % 10) ** 2
            n //= 10
        return nn
