class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        i = 0
        while i < len(s):
            if s[i] == part[0] and i + len(part) - 1 <= len(s) and s[i:i+len(part)] == part:
                s = s[:i] + s[i+len(part):]
                i -= len(part)
                if i < 0:
                    i = -1

            i += 1

        return s