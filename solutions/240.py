class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        not_power_of_2 = not (n & (n - 1))
        not_divisible_by_3 = n % 3 == 1

        return n > 0 and not_power_of_2 and not_divisible_by_3
