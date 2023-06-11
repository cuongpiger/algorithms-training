"""
Time Complexity: O(N)
Space Complexity: O(N)

- N: Number of digits in x
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        digits = []

        while x > 0:
            digits.append(x % 10)
            x = x // 10

        l = len(digits)
        for i in range(len(digits) // 2):
            if digits[i] != digits[l - 1 - i]:
                return False

        return True
    