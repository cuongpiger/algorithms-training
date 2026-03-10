class Solution:
    def reverse(self, x: int) -> int:
        rev_num = 0
        int_min = 2**31 * -1
        int_max = 2**31 - 1

        sign = -1 if x < 0 else 1
        x = abs(x)
        while x > 0:
            pop = x % 10
            x //= 10
            rev_num = rev_num * 10 + pop

            if not (int_min <= sign * rev_num <= int_max):
                return 0

        return sign * rev_num
