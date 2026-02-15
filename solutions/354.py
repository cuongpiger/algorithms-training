class Solution:
    def binaryGap(self, n: int) -> int:
        s = bin(n)[2:]  # remove '0b'
        last = None
        ans = 0
        for i, ch in enumerate(s):
            if ch == '1':
                if last is not None:
                    ans = max(ans, i - last)
                last = i
        return ans
