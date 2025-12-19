class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_scores = sorted([(x, i) for i, x in enumerate(score)], reverse=True)
        res = ["" for _ in range(len(score))]

        for i in range(len(sorted_scores)):
            idx = sorted_scores[i][1]
            if i == 0:
                res[idx] = "Gold Medal"
            elif i == 1:
                res[idx] = "Silver Medal"
            elif i == 2:
                res[idx] = "Bronze Medal"
            else:
                res[idx] = f"{i+1}"

        return res
