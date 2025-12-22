class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        num_batches = (n // k) + int((n % k) != 0)
        res = ""

        for i in range(0, num_batches):
            start = k * i
            end = min(start + k, n)
            if i % 2 == 0:
                res += s[start:end][::-1]
            else:
                res += s[start:end]

        return res
