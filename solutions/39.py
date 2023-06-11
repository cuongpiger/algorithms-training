"""
Time Complexity: O(n)

n: length of s
"""

class Solution:
    def isValid(self, s: str) -> bool:
        cnt = [0, 0, 0]
        parentheses = {
            '(': (0, 1),
            ')': (0, -1),
            '{': (1, 1),
            '}': (1, -1),
            '[': (2, 1),
            ']': (2, -1)
        }
        pairs = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        last = ""
        for ch in s:
            idx, scr = parentheses.get(ch)
            cnt[idx] += scr

            if cnt[idx] < 0:
                return False

            if ch in ('[', '{', '('):
                last += ch
                continue

            if last != "" and pairs.get(ch) != last[-1]:
                return False

            last = last[:-1]

        for v in cnt:
            if v != 0:
                return False

        return True 

