'''
https://www.codechef.com/problems/COMPILER
Comment
'''
import sys

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

if __name__ == '__main__':
    #FILE_IO()
    tc = int(input())

    for _ in range(tc):
        eps = str(input())
        cnt = 0
        balance = -1

        for i in range(len(eps)):
            cnt += 1 if eps[i] == '<' else -1

            if cnt == 0:
                balance = i
            elif cnt < 0:
                break

        if balance != -1:
            print(balance + 1)
        else:
            print(0)