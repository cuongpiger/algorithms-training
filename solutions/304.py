# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if root1 is None:
            return root2

        if root2 is None:
            return root1

        new_node = None
        if root1 != None and root2 != None:
            new_node = TreeNode(
                root1.val + root2.val,
                self.mergeTrees(root1.left, root2.left),
                self.mergeTrees(root1.right, root2.right)
            )

        return new_node
