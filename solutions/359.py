direc = [(0, 1), (0, -1), (1, 0), (-1, 0)]

class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        def getVal(grid, i, j, x, y, n):
            if x < 0 or y < 0 or x >= n or y >= n:
                return 0

            diff = grid[x][y] - grid[i][j]
            if diff > 0:
                return diff

            return 0

        res = 0
        n = len(grid)
        if n == 1:
            res = grid[0][0] * 4
            return res + 2 if res > 0 else 0

        for i in range(n):
            for j in range(n):
                if grid[i][j] > 0:
                    res += 2

                if i == 0 or i == n - 1:
                    res += grid[i][j]

                if j == 0 or j == n - 1:
                    res += grid[i][j]

                for x, y in direc:
                    x = x + i
                    y = y + j
                    res += getVal(grid, i, j, x, y, n)

        return res


