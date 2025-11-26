# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.leftRight(root) == self.rightLeft(root)

    def leftRight(self, root) -> str:
        if root is None:
            return "_"

        left_none = root.left is None
        right_none = root.right is None

        if left_none == right_none == True:
            return f"{root.val}"
        else:
            return f"{self.leftRight(root.left)}{self.leftRight(root.right)}{root.val}"

    def rightLeft(self, root) -> str:
        if root is None:
            return "_"

        left_none = root.left is None
        right_none = root.right is None

        if left_none == right_none == True:
            return f"{root.val}"
        else:
            return f"{self.rightLeft(root.right)}{self.rightLeft(root.left)}{root.val}"
