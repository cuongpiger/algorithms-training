# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        self.visited = dict()
        self.result = False
        self.dfs(root, k)
        return self.result

    def dfs(self, root, k):
        if root is None:
            return

        if self.result == True:
            return

        val = k - root.val
        if not self.visited.get(val, False):
            self.visited[root.val] = True
            self.dfs(root.left, k)
            self.dfs(root.right, k)
        else:
            self.result = True
