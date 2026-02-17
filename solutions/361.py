# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        dummy = TreeNode(0)   # helps build the chain easily
        prev = dummy

        def inorder(node):
            nonlocal prev
            if not node:
                return
            inorder(node.left)

            # rewire current node
            node.left = None
            prev.right = node
            prev = node

            inorder(node.right)

        inorder(root)
        return dummy.right
