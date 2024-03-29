'''
http://codeforces.com/problemset/problem/520/A
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

#_____main_____
#FILE_IO()

cnt = [0]*26

n = int(input())
seq = str(input())
seq = list(seq.lower())
res = 'YES'

for char in seq:
    cnt[ord(char) - 97] += 1

for i in cnt:
    if i == 0:
        res = 'NO'
        break

print(res)
