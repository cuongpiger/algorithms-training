"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""


class Solution:
    result = 0

    def maxDepth(self, root: "Node") -> int:
        self.dfs(root, 1)
        return self.result

    def dfs(self, root, depth):
        if not root:
            return

        self.result = max(self.result, depth)
        if root.children is None:
            return

        for child in root.children:
            self.dfs(child, depth + 1)
