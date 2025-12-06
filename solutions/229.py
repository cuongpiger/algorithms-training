# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        queue = deque()
        queue.append((root, ""))
        result = []

        while len(queue) > 0:
            node, prefix = queue.popleft()
            if node.left == node.right == None:
                result.append(f"{prefix}{node.val}")
            else:
                new_path = f"{prefix}{node.val}->"
                if node.left is not None:
                    queue.append((node.left, new_path))

                if node.right is not None:
                    queue.append((node.right, new_path))

        return result
