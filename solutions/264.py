direction = ((0, 1), (0, -1), (1, 0), (-1, 0))


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        res = 0

        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0:
                    continue

                for dx, dy in direction:
                    newx = dx + i
                    newy = dy + j

                    if 0 <= newx < row and 0 <= newy < col:
                        res += int(grid[newx][newy] == 0)
                    else:
                        res += 1

        return res
