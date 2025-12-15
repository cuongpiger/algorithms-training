class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g = sorted(g)
        s = sorted(s)
        glen = len(g)
        slen = len(s)
        gi, si = 0, 0
        res = 0

        while gi < glen and si < slen:
            if g[gi] <= s[si]:
                gi += 1
                si += 1
                res += 1
            elif s[si] < g[gi]:
                si += 1

        return res
