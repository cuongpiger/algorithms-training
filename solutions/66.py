class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        list_numbers = []
        for elem in nums1:
            list_numbers.append(elem)

        for elem in nums2:
            list_numbers.append(elem)

        list_numbers.sort()
        idx = len(list_numbers) // 2
        
        if len(list_numbers) % 2 == 0:
            return (list_numbers[idx] + list_numbers[idx - 1]) / 2
        else:
            return list_numbers[idx]