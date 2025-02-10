class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        cache_indexers = [0 for _ in range(105)]
        for v in nums:
            cache_indexers[v] += 1

        res = []
        for i, v in enumerate(cache_indexers):
            if v == 2:
                res.append(i)

        return res