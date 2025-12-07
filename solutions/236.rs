/*
You can win the Nim Game for all n except when n is a multiple of 4. So the solution is: return n % 4 != 0.​

Intuition
Try small values:

n = 1, 2, 3: you can take all stones in one move → you win.​

n = 4: whatever you take (1, 2, or 3), you leave 3, 2, or 1, and your friend takes the rest → you lose.​

Now notice the pattern:

If you start with 4, you lose. If you start with 5, 6, 7, you can remove 1, 2, 3 stones to leave 4 for your friend, forcing a losing position on them.​

Then 8 is losing again, for the same reason, and so on. Every multiple of 4 is losing; all others are winning if you play optimally.
*/
impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        n % 4 != 0
    }
}
