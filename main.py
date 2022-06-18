def get_input():
    N, M = list(map(int, input().strip().split()))
    
    sea = []
    for _ in range(N):
        r = list(map(int, input().strip().split()))
        sea.append(r)
        
    return N, M, sea


def solve(N: int, M: int, sea: List[List[int]]):
    pass