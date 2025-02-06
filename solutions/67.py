def findMax(a: int, b: int) -> int:
    return a if a >= b else b

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        cache = set() 
        res = 0

        if len(s) > 0:
            cache = {s[0]}
            res = 1

        i = 0
        j = 1

        while j < len(s):
            cache.add(s[j])

            if len(cache) == j - i + 1:
                j = j + 1
                res = findMax(res, len(cache))
            else:
                i = i + 1
                j = i + 1

                if i < len(s):                
                    cache = {s[i]}

        return res





