'''
https://codeforces.com/contest/1073/problem/A
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

n = int(input())
s = list(input())

for i in range(1, n):
    if s[i] != s[i - 1]:
        print('YES')
        print(''.join(s[i - 1: i + 1]))
        exit(0)

print('NO')
