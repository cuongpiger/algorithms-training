# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)

        if left_depth > 0 and right_depth > 0:
            return 1 + min(left_depth, right_depth)
        elif left_depth > 0:
            return 1 + left_depth
        else:
            return 1 + right_depth
