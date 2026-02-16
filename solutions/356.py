class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        xz = sum([max(row) for row in grid])
        yz = sum([max([grid[i][j] for i in range(len(grid))]) for j in range(len(grid))])
        return xz + yz + sum(1 for row in grid for x in row if x > 0)
