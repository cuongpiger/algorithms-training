# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.root.val = 0
        self.numbers = dict()
        self._travel(self.root)
        
    def find(self, target: int) -> bool:
        return self.numbers.get(target, False)

    def _travel(self, node: Optional[TreeNode]):
        if node is not None:
            self.numbers[node.val] = True

            if node.left is not None:
                node.left.val = 2 * node.val + 1
                self._travel(node.left)

            if node.right is not None:
                node.right.val = 2 * node.val + 2
                self._travel(node.right)

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)