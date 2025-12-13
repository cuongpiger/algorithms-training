# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self._sum_left(0, root)

    def _sum_left(self, side: int, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if root.left == root.right == None:
            if side < 0:
                return root.val
            return 0

        return self._sum_left(-1, root.left) + self._sum_left(1, root.right)
