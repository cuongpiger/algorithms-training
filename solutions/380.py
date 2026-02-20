# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: Optional[TreeNode], x: int, y: int) -> bool:
        x_info = (0, 0)
        y_info = (0, 0)

        def dfs(node, parent, depth):
            nonlocal x_info, y_info
            if node is None:
                return

            if node.val == x:
                x_info = (parent, depth)
            elif node.val == y:
                y_info = (parent, depth)

            dfs(node.left, node.val, depth + 1)
            dfs(node.right, node.val, depth + 1)

        dfs(root, 0, 1)
        return x_info[0] != y_info[0] and x_info[1] == y_info[1]
