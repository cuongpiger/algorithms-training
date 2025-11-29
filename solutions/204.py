class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        res = 0
        for i, ch in enumerate(columnTitle[::-1]):
            if i == 0:
                res += self.parse(ch)
            else:
                res += self.parse(ch) * 26**i

        return res

    def parse(self, ch) -> int:
        return ord(ch) - ord("A") + 1
