"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""


class Solution:
    def preorder(self, root: "Node") -> List[int]:
        self.result = []
        self.dfs(root)
        return self.result

    def dfs(self, root):
        if root is None:
            return

        self.result.append(root.val)
        if len(root.children) > 0:
            for i in range(0, len(root.children)):
                child = root.children[i]
                self.dfs(child)
