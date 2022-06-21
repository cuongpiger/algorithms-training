import sys
from queue import Queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    
def get_input():
    key, lock = map(int, input().split())
    input()
    other_keys = list(map(int, input().split()))
    
    return key, lock, other_keys

def bfs(key, lock, other_keys):
    q = Queue()
    q.put(key)
    visited = dict()
    visited[key] = 0
    
    while not q.empty():
        key_comb = q.get()
        key_comb_visited = visited.get(key_comb)
        
        for ok in other_keys:
            new_key_comb = (key_comb * ok) % 100000

            if visited.get(new_key_comb) is None:
                visited[new_key_comb] = key_comb_visited + 1
                q.put(new_key_comb)
                
                if new_key_comb == lock:
                    return visited.get(new_key_comb)
                
    return -1     

def solve():
    key, lock, other_keys = get_input()
    res = bfs(key, lock, other_keys)
    print(res)
    
    
# FILE_IO()
solve()