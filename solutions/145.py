def backtracking(nums: List[int], current_xor: int, current_index: int):
    if current_index >= len(nums):
        return current_xor

    with_element = backtracking(
        nums, current_xor ^ nums[current_index], current_index + 1
    )
    without_element = backtracking(nums, current_xor, current_index + 1)

    return with_element + without_element


class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        return backtracking(nums, 0, 0)
