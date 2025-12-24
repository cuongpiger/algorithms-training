# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = 0

    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res

    def dfs(self, root):
        if root is None:
            return 0

        if root.left == root.right == None:
            return root.val

        left = self.dfs(root.left)
        right = self.dfs(root.right)
        self.res += abs(left - right)
        return root.val + left + right
