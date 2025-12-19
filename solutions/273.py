class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return "0"

        res = ""
        prefix = "" if num >= 0 else "-"

        num = abs(num)
        while num > 0:
            res = f"{num % 7}{res}"
            num //= 7

        return f"{prefix}{res}"
