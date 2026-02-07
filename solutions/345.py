class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        ans = [0 if ch == c else 10**5 for ch in s]

        for i in range(len(ans)):
            if ans[i] == 0:
                j = i - 1
                while j > -1 and ans[j] != 0:
                    ans[j] = min(ans[j], i - j)
                    j -= 1

        for i in range(len(ans) - 1, -1, -1):
            if ans[i] == 0:
                j = i + 1
                while j < len(ans) and ans[j] != 0:
                    ans[j] = min(ans[j], j - i)
                    j += 1

        return ans
