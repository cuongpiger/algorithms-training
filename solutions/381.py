class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        relations = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
        for source, target in trust:
            relations[source][target] = 1

        for j in range(1, n + 1):
            if sum([relations[i][j] for i in range(1, n + 1)]) == n - 1 and sum(relations[j]) == 0:
                return j

        return -1
