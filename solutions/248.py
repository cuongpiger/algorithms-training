class Solution:
    def firstUniqChar(self, s: str) -> int:
        digits = [0 for _ in range(26)]
        for ch in s:
            digits[ord(ch) - ord('a')] += 1

        for i, ch in enumerate(s):
            if digits[ord(ch) - ord('a')] == 1:
                return i

        return -1
