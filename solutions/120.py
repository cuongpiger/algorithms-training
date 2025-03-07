class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        cache = [0] * (len(grid)**2 + 1)
        for i in range(len(grid)):
            for j in range(len(grid)):
                cache[grid[i][j]] += 1

        first = 0
        second = 0
        for i in range(1, len(cache)):
            if cache[i] == 2:
                first = i
            elif cache[i] == 0:
                second = i

        return [first, second]
        