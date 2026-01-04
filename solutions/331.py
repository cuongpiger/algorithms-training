class Solution:
    def floodFill(
        self, image: List[List[int]], sr: int, sc: int, color: int
    ) -> List[List[int]]:
        m, n = len(image), len(image[0])
        start = image[sr][sc]
        if start == color:
            return image

        q = deque()
        q.append((sr, sc))
        image[sr][sc] = color

        while q:
            r, c = q.popleft()
            for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and image[nr][nc] == start:
                    image[nr][nc] = color
                    q.append((nr, nc))
        return image
