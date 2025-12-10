class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        intersec = [0 for _ in range(1010)]
        for x in nums1:
            intersec[x] = 1

        for x in nums2:
            intersec[x] = 2 if intersec[x] > 0 else 0

        return [i for i, x in enumerate(intersec) if x > 1]
