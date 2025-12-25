# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot == None:
            return True

        if root == None:
            return False

        if self.same(root, subRoot):
            return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)

    def same(self, r, s):
        if r == None and s == None:
            return True

        if r and s and r.val == s.val:
            return self.same(r.right, s.right) and self.same(r.left, s.left)

        return False
