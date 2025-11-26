# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self._findNewRoot(0, len(nums), nums)


    def _findNewRoot(self, left, right, nums) -> TreeNode:
        if left < right:
            mid = left + (right - left) // 2
            return TreeNode(nums[mid], self._findNewRoot(left, mid, nums), self._findNewRoot(mid + 1, right, nums))

        return None
