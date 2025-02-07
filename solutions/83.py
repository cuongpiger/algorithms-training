# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right



def travel(res: dict, depth: int, node):
    min_inf = -2147483948

    if node is None:
        return
    
    max_val = res.get(depth, min_inf)
    res[depth] = max(max_val, node.val)

    travel(res, depth + 1, node.left)
    travel(res, depth + 1, node.right)


class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res = dict()
        travel(res, 1, root)
        
        final_res = []
        for _, v in sorted(res.items()):
            final_res.append(v)

        return final_res