import queue

def solve(current_index: int, pattern: str, previous_digit: int, visited: List[bool], min_heap: queue.PriorityQueue, value: str):
    if current_index == -1:
        for i in range(1, len(pattern) + 2):
            visited[i] = True
            solve(0, pattern, i, visited, min_heap, f"{i}")
            visited[i] = False
        
        return

    if current_index >= len(pattern):
        min_heap.put(int(value))
    else:
        for i in range(1, len(pattern) + 2):
            if not visited[i]:
                if pattern[current_index] == "I":
                    if i > previous_digit:
                        visited[i] = True
                else:
                    if i < previous_digit:
                        visited[i] = True

                if visited[i]:
                    tmp = f"{value}{i}"
                    solve(current_index + 1, pattern, i, visited, min_heap, tmp)
                    visited[i] = False      



class Solution:
    def smallestNumber(self, pattern: str) -> str:
        res = queue.PriorityQueue()
        visited = [False for _ in range(len(pattern) + 2)]
        solve(-1, pattern, -1, visited, res, "")

        return str(res.get())
