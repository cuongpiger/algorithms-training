class Solution:
    def findComplement(self, num: int) -> int:
        bit_len = num.bit_length()
        mask = (1 << bit_len) - 1
        return num ^ mask
