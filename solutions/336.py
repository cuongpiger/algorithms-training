class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        c = 0
        for i in range(left, right + 1):
            bits = bin(i).count("1")
            if self.isPrime(bits):
                c += 1
        return c

    def isPrime(self, n: int) -> bool:
        if n < 2:
            return False
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True
