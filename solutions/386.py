from typing import Tuple


class Solution:
    def longestPalindrome(self, s: str) -> str:
        nlen = len(s)
        if nlen <= 1:
            return s

        def expand_from_center(left: int, right: int) -> Tuple[int, int]:
            while left >= 0 and right < nlen and s[left] == s[right]:
                left -= 1
                right += 1
            return left + 1, right - 1

        start, end = 0, 0
        for i in range(nlen):
            l1, r1 = expand_from_center(i, i)
            l2, r2 = expand_from_center(i, i + 1)

            if r1 - l1 > end - start:
                start, end = l1, r1

            if r2 - l2 > end - start:
                start, end = l2, r2

        return s[start : end + 1]
