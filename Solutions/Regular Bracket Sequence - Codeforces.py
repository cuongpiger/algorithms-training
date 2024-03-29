'''
https://codeforces.com/problemset/problem/26/B
Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

#_____main_____
#FILE_IO()

seq = list(input())
cnt = res = 0

for ch in seq:
    if ch == '(':
        cnt += 1
    else:
        if cnt:
            res += 2
            cnt -= 1

print(res)
