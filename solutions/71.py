class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        colors = dict()
        balls = dict()
        res = []

        for q in queries:
            # print(f"Query: {q}")
            ball, color = q[0], q[1]
            found_ball_color = balls.get(ball, None)

            if found_ball_color is None:
                balls[ball] = color
                set_balls = colors.get(color, set())
                set_balls.add(ball)
                colors[color] = set_balls
            else:
                if found_ball_color != color:
                    set_balls = colors.get(found_ball_color, set())
                    set_balls.discard(ball)
                    colors[found_ball_color] = set_balls

                    if len(set_balls) < 1:
                        colors.pop(found_ball_color, None)


                    set_balls = colors.get(color, set())
                    set_balls.add(ball)
                    colors[color] = set_balls
                    balls[ball] = color
                    # print(f"Color set: {colors}")

            res.append(len(colors))


        return res