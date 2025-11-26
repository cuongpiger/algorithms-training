# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self._calcDepth(root) != -1

    def _calcDepth(self, root) -> int:
        if root is None:
            return 0

        left_depth = self._calcDepth(root.left)
        if left_depth == -1:
            return -1

        right_depth = self._calcDepth(root.right)
        if right_depth == -1:
            return -1

        if abs(left_depth - right_depth) > 1:
            return -1

        return 1 + max(left_depth, right_depth)
