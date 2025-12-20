class Solution:
    cache = {}

    def fib(self, n: int) -> int:
        if n == 0:
            return 0

        if n == 1:
            return 1

        val = self.cache.get(n, None)
        if val is not None:
            return val

        val = self.fib(n - 1) + self.fib(n - 2)
        self.cache[n] = val
        return val
