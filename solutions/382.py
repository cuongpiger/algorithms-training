class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        xR, yR = 0, 0
        res = 0
        for i in range(8):
            for j in range(8):
                if board[i][j] == "R":
                    xR = i
                    yR = j
                    break

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for dx, dy in directions:
            next_xR, next_yR = xR + dx, yR + dy
            counter = 0
            while 0 <= next_xR < 8 and 0 <= next_yR < 8:
                if board[next_xR][next_yR] == ".":
                    next_xR, next_yR = next_xR + dx, next_yR + dy
                elif board[next_xR][next_yR] == "p":
                    counter += 1
                else:
                    counter += 2

                if counter >= 1:
                    res += int(counter == 1)
                    break

        return res
