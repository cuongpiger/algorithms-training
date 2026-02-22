class Solution:
    def bitwiseComplement(self, n: int) -> int:
        bin_str = ""
        while n > 0:
            digit = 1 - (n & 1)
            bin_str = f"{digit}{bin_str}"
            n >>= 1

        return int(bin_str, 2) if bin_str != "" else 1
