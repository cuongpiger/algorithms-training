'''
https://www.hackerrank.com/challenges/find-the-median/problem
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''


#_____main_____
#FILE_IO()

n = int(input())
arr = list(map(int, input().split()))

arr.sort()
print(arr[int(n / 2)])