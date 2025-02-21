def indexChar(charac: str) -> int:
    return ord(charac) - ord('a')

class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        res = (n + 1) * n // 2
        count = [0 for _ in range(26)]
        i = 0
        
        for j in range(n):
            count[indexChar(s[j])] += 1

            while count[indexChar(s[j])] >= k:
                count[indexChar(s[i])] -= 1
                i += 1

            res -= j - i + 1

        return res
