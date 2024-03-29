'''
https://codeforces.com/problemset/problem/600/B
Comment
'''
import sys
import bisect

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

#_____main_____
#FILE_IO()

n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = []
dic = dict()

for elm in b:
    c.append(elm)

a.sort()
b.sort()
i = j = 0

while i < m:
    while j < n and a[j] <= b[i]:
        j += 1

    dic[b[i]] = j
    i += 1

for elm in c:
    print(dic[elm], end = ' ')
    