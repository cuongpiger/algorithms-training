'''
https://codeforces.com/problemset/problem/499/B
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

if __name__ == '__main__':
    #FILE_IO()
    n, m = map(int, input().split())
    dic = dict()

    for _ in range(m):
        a, b = input().split()

        if len(a) <= len(b):
            b = a

        dic[a] = b
    
    profes = list(input().split())

    for word in profes:
        if word in dic:
            print(dic[word], end = ' ')
        else:
            print(word, end = ' ')

    