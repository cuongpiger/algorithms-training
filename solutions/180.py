class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = []
        leftover = 1

        for x in reversed(digits):
            x = x + leftover
            if x > 9:
                res.append(x % 10)
                leftover = x // 10
            else:
                res.append(x)
                leftover = 0

        if leftover > 0:
            res.append(leftover)

        return res[::-1]
