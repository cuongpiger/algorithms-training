class Solution:
    
    def validPalindrome(self, s: str) -> bool:
        return self.solve(s, len(s), 0, len(s) - 1, 0) <= 1

    def solve(self, s, n, l, r, cnt) -> int:
        if 0 <= l < n and 0 <= r < n and l <= r and cnt < 2:
            if s[l] == s[r]:
                return self.solve(s, n, l + 1, r - 1, cnt)
            else:
                left = self.solve(s, n, l + 1, r, cnt + 1)
                right = self.solve(s, n, l, r - 1, cnt + 1)
                return min(left, right)

        return cnt
