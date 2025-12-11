class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i, j = 0, 0
        while i < len(s):
            if j >= len(t):
                break

            while j < len(t):
                if t[j] == s[i]:
                    i += 1
                    j += 1
                    break
                else:
                    j += 1

        return i >= len(s)
