"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        self.result = []
        self.dfs(root)
        return self.result

    def dfs(self, root):
        if root is None:
            return

        for child in root.children:
            self.dfs(child)

        self.result.append(root.val)
