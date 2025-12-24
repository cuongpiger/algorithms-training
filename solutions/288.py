class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        if m * n != r * c:
            return mat

        res = [[0 for _ in range(c)] for _ in range(r)]
        for i in range(m):
            for j in range(n):
                k = i * n + j
                new_j = k % c
                new_i = (k - new_j) // c
                res[new_i][new_j] = mat[i][j]

        return res
