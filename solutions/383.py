class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        board = [[0 for _ in range(26)] for _ in range(len(words))]

        for i, word in enumerate(words):
            for ch in word:
                board[i][ord(ch) - ord('a')] += 1

        res = []
        n = len(words)
        for i in range(26):
            filter_vals = [board[j][i] for j in range(n) if board[j][i] > 0]
            if len(filter_vals) == n:
                res += [chr(ord('a') + i)] * min(filter_vals)

        return res
