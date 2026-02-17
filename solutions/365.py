class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        english_characters = [x for x in s if ord("a") <= ord(x) <= ord("z") or ord("A") <= ord(x) <= ord("Z")][::-1]
        res = ""
        k = 0
        for x in s:
            if ord("a") <= ord(x) <= ord("z") or ord("A") <= ord(x) <= ord("Z"):
                res += english_characters[k]
                k += 1
            else:
                res += x

        return "".join(res)
