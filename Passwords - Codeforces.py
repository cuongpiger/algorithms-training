#https://codeforces.com/problemset/problem/721/B
'''
Comment
'''
 
if __name__ == "__main__":
    n, k = map(int, input().split())
    leng = [0 for _ in range(105)]
 
    for _ in range(n):
        line = str(input())
        leng[len(line)] += 1
 
    line = str(input());
    acPass = len(line)
    summ = sum(leng[1: acPass + 1])
 
    res1 = (summ - leng[acPass]) + int((summ - leng[acPass]) / k) * 5 + 1
    res2 = summ + int((summ - 1) / k) * 5
    print(res1, res2)