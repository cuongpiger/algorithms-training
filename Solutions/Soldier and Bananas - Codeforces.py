'''
http://codeforces.com/problemset/problem/546/A
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

k, n, w = map(int, input().split())

cost = ((w*(w + 1))/2)*k;
res = cost - n if cost > n else 0

print(int(res))
