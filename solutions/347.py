class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        res = []
        i = 0
        n = len(s)

        while i < n:
            j = i + 1
            while j < n and s[i] == s[j]:
                j += 1

            if j - i - 1 >= 2:
                res.append([i, j - 1])

            i = j
        
        return res
