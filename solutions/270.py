class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_greater = {}
        stack = []

        for num in reversed(nums2):
            while len(stack) > 0 and stack[-1] <= num:
                stack = stack[:-1]

            next_greater[num] = -1 if len(stack) < 1 else stack[-1]
            stack.append(num)

        return [next_greater[num] for num in nums1]
