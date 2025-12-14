class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 1, n
        res = 0
        while left <= right:
            mid = left + (right - left) // 2
            if n >= (mid * (mid + 1)) / 2:
                left = mid + 1
                res = mid
            else:
                right = mid - 1

        return res

    def arrangeCoins2(self, n: int) -> int:
        return int(-0.5 + sqrt(2*n + 0.25))
