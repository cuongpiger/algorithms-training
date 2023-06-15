# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        cache = {}
        res = []

        def dfs(node, level):
            if node is None:
                return

            v = cache.get(level, [])
            cache[level] = v + [node.val]
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)

        dfs(root, 1)
        for k, v in cache.items():
            res.append((-sum(v), k))

        res.sort()
        return res[0][1]
