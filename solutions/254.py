from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = Counter(s)
        length = 0
        has_odd = False

        for cnt in freq.values():
            if cnt % 2 == 0:
                length += cnt  # use all even
            else:
                length += cnt - 1  # use even part
                has_odd = True  # remember there is an odd

        if has_odd:
            length += 1  # one odd goes in the center

        return length
