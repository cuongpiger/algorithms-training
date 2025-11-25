class Solution:
    def mySqrt(self, x: int) -> int:
        left = 1
        right = x // 2 + 1
        res = 0

        while left <= right:
            mid = left + (right - left) // 2
            if mid <= x / mid:
                res = mid
                left = mid + 1
            else:
                right = mid - 1

        return res
