class Solution:
    def countSegments(self, s: str) -> int:
        res = 0
        n = len(s)
        i = 0

        while i < n:
            if s[i] == " ":
                i += 1
            else:
                j = i + 1
                while j < n:
                    if s[j] == " ":
                        break
                    else:
                        j += 1

                i = j
                res += 1
        
        return res
