class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        elements = sorted([x for row in grid for x in row])
        median = elements[len(elements) // 2]

        res = 0
        for val in elements:
            if val % x != median % x:
                return -1

            res += abs(val - median) // x

        return res