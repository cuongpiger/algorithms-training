# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def travel(root):
            if root is None:
                return []

            if root.left == root.right == None:
                return [root.val]

            left = travel(root.left)
            right = travel(root.right)

            return left + right

        travel_1 = travel(root1)
        travel_2 = travel(root2)

        if len(travel_1) != len(travel_2):
            return False


        for x, y in zip(travel_1, travel_2):
            if x != y:
                return False

        return True
