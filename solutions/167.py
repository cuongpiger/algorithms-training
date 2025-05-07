from typing import List

MOD = 10**9 + 7


def solve(depth: int, cur_depth: int, state: int, dp: List[List[int]]) -> int:
    """
    Parameters:
    - state: 0 - no overhangs, 1 - top overhang, 2 - bottom overhang
    """
    if cur_depth == depth:
        return 1 if state == 0 else 0

    if cur_depth > depth:
        return 0

    if dp[cur_depth][state] != -1:
        return dp[cur_depth][state]

    ans = 0
    top_hang = solve(depth, cur_depth + 1, 2, dp)
    bot_hang = solve(depth, cur_depth + 1, 1, dp)
    trommino = solve(depth, cur_depth + 2, 0, dp)
    vertical = solve(depth, cur_depth + 1, 0, dp)

    if state == 0:
        if cur_depth + 1 < depth:
            ans = (ans + top_hang) % MOD
            ans = (ans + bot_hang) % MOD
            ans = (ans + trommino) % MOD

        ans = (ans + vertical) % MOD
    elif state == 1:
        if cur_depth + 1 < depth:
            ans = (ans + top_hang) % MOD
            ans = (ans + trommino) % MOD
        else:
            return 0
    else:  # state is equal to 2
        if cur_depth + 1 < depth:
            ans = (ans + bot_hang) % MOD
            ans = (ans + trommino) % MOD
        else:
            return 0

    dp[cur_depth][state] = ans
    return ans


class Solution:
    def numTilings(self, n: int) -> int:
        dp = [[-1] * 3 for _ in range(n + 1)]
        res = solve(n, 0, 0, dp)
        return res
