class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        cnt = 0
        for x in word:
            ord_val = ord(x)

            if ord_val >= 97:
                cnt += 1
            else:
                cnt += 2

        n = len(word)
        return cnt == n or cnt == 2*n or (cnt == n + 1 and ord(word[0]) < 97)
