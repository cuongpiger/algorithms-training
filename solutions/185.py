# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        left_none = root.left is None
        right_none = root.right is None

        if left_none and right_none:
            return [root.val]
        elif not (left_none or right_none):
            return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)
        elif left_none:
            return [root.val] + self.inorderTraversal(root.right)
        else:
            return self.inorderTraversal(root.left) + [root.val]
