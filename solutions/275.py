class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 0 or num % 2 == 1:
            return False

        sm = 3
        for i in range(3, num // 2 + 1):
            if num % i == 0:
                sm += i

        return sm == num
