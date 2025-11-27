from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 1:
            return [1]
        
        if rowIndex == 2:
            return [1, 1]

        prev_row = self.getRow(rowIndex - 1)
        return [1] + [prev_row[j] + prev_row[j - 1] for j in range(1, rowIndex - 1)] + [1]

sol = Solution()
print(sol.getRow(4))  # Output: [1, 3, 3, 1]
