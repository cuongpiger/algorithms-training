class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        k = 0
        for s in reversed(s):
            if s != " ":
                k += 1
            elif k > 0:
                break

        return k
