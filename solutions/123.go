/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    var res = new(ListNode)
    digDown(head, 1, res)

    fmt.Println(res)
    return res
}

func digDown(cur *ListNode, depth int, res *ListNode) int {
    if cur == nil {
        return (depth - 1) / 2 + 1
    }

    chainDepth := digDown(cur.Next, depth + 1, res)
    if chainDepth == depth {
        res.Val = cur.Val
        res.Next = cur.Next
    }

    return chainDepth
}