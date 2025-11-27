class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]

        if numRows == 2:
            return [[1], [1, 1]]

        upper = self.generate(numRows - 1)
        prev = upper[-1]
        row = [1] + [prev[j] + prev[j - 1] for j in range(1, numRows - 1)] + [1]
        upper.append(row)
        return upper
