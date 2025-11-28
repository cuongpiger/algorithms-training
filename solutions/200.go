/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
	if root == nil {
		return make([]int, 0)
	}

	left := postorderTraversal(root.Left)
	right := postorderTraversal(root.Right)

	return append(append(left, right...), root.Val)
}
