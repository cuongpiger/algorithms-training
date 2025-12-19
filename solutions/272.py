# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    prev = None
    max_count = 0
    current_count = 0
    result = []

    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        return self.result

    def dfs(self, root):
        if root is None:
            return

        self.dfs(root.left)
        self.current_count = 1 if root.val != self.prev else self.current_count + 1

        if self.current_count == self.max_count:
            self.result.append(root.val)
        elif self.current_count > self.max_count:
            self.max_count = self.current_count
            self.result = [root.val]

        self.prev = root.val
        self.dfs(root.right)
