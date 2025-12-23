class Solution:
    def reverseWords(self, s: str) -> str:
        i = 0
        n = len(s)
        res = ""

        while i < n:
            if s[i] != " ":
                j = i
                word = ""
                while j < n:
                    if s[j] != " ":
                        word = f"{s[j]}{word}"
                        j += 1
                    else:
                        break

                res += word
                i = j
            else:
                res += " "
                i += 1

        return res
