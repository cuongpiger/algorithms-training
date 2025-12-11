class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        count = [0 for _ in range(26)]
        for ch in s:
            count[ord(ch) - ord('a')] += 1

        for ch in t:
            count[ord(ch) - ord('a')] += 1

        for i, cnt in enumerate(count):
            if cnt % 2 == 1:
                return chr(ord('a') + i)

        return ''
