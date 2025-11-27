from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # res = []

        # for n in range(1, 3):
        #     res.append([1 for _ in range(n)])
        #     if n == numRows:
        #         return res

        # for i in range(3, numRows + 1):
        #     prev = res[-1]
        #     row = [1] + [prev[j] + prev[j - 1] for j in range(1, i - 1)] + [1]
        #     res.append(row)

        # return res

        return self._solve(numRows)

    def _solve(self, n: int) -> List[List[int]]:
        if n == 1:
            return [[1]]

        if n == 2:
            prev_result = self._solve(1)
            prev_result.append([1, 1])
            return prev_result

        upper = self._solve(n - 1)
        prev = upper[-1]
        row = [1] + [prev[j] + prev[j - 1] for j in range(1, n - 1)] + [1]
        upper.append(row)
        return upper
    

n = 5
sol = Solution()
print(sol.generate(n))
