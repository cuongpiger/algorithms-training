# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        self.result = set()
        self.dfs(root)
        return -1 if len(self.result) < 2 else sorted(self.result)[1]

    def dfs(self, root):
        if root is None:
            return

        self.result.add(root.val)
        self.dfs(root.left)
        self.dfs(root.right)
