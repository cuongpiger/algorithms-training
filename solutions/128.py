class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        arr = sorted(nums1[:m] + nums2[:n])
        for i in range(len(arr)):
            nums1[i] = arr[i]