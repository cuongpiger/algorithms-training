# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(root, prev_val):
            if root is None:
                return True

            if root.val != prev_val:
                return False

            return dfs(root.left, prev_val) and dfs(root.right, prev_val)

        return dfs(root, root.val)
