# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        return self._sumPath(root, targetSum, 0, (root.left == root.right == None))

    def _sumPath(self, root, target_sum, cur_sum, is_leaf_node) -> bool:
        if root is None:
            if cur_sum == target_sum and is_leaf_node:
                return True
            else:
                return False

        leaf_node = (root.left == root.right == None)

        return self._sumPath(root.left, target_sum, cur_sum + root.val, leaf_node) or self._sumPath(root.right, target_sum, cur_sum + root.val, leaf_node)
