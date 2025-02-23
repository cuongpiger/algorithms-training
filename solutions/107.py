# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        return construct_tree(0, len(preorder) - 1, 0, preorder, postorder)



def construct_tree(pre_start: int, pre_end: int, post_start: int, pre_order: List[int], post_order: List[int]) -> Optional[TreeNode]:
    # Base case: If there are no nodes to process, return None
    if pre_start > pre_end:
        return None

    # Base case: If only one node is left, return that node
    if pre_start == pre_end:
        return TreeNode(pre_order[pre_start])

    # If the left child root in preorder traversal (next element after root)
    left_root = pre_order[pre_start + 1]

    # Calculate the number of nodes in the left subtree by searching in post_order
    number_of_nodes_in_left = 1
    while post_order[post_start + number_of_nodes_in_left - 1] != left_root:
        number_of_nodes_in_left += 1

    root = TreeNode(pre_order[pre_start])
    root.left = construct_tree(pre_start + 1, pre_start + number_of_nodes_in_left, post_start, pre_order, post_order)
    root.right = construct_tree(pre_start + number_of_nodes_in_left + 1, pre_end, post_start + number_of_nodes_in_left, pre_order, post_order)

    return root