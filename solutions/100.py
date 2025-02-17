def solve(visited: List[bool], tiles: str, prefix: str, res: set):
    for i, visit in enumerate(visited):
        if not visit:
            visited[i] = True
            tmp = prefix
            prefix += tiles[i]
            res.add(prefix)
            solve(visited, tiles, prefix, res)
            prefix = tmp
            visited[i] = False


class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        word_bags = set()
        visited = [False for _ in range(len(tiles))]
        solve(visited, tiles, "", word_bags)

        return len(word_bags)
        