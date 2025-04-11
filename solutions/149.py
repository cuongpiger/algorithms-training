class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        res = 0
        for value in range(low, high + 1):
            if value < 100 and value % 11 == 0:
                res += 1
            elif 1000 <= value < 10000:
                left = (value // 1000) + (value % 1000 // 100)
                right = (value % 100 // 10) + (value % 10)
                res += int(left == right)

        return res