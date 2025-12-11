class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left = 1
        right = max(num // 2, 1)

        while left <= right:
            mid = (left + (right - left) // 2)
            val = mid * mid
            if val < num:
                left = mid + 1
            elif val > num:
                right = mid - 1
            else:
                return True

        return False
