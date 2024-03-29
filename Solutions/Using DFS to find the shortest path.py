'''

Comment
'''
import sys
import queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

'''____________________________________________________________________________________________'''

INF = 10 ** 9
grp = [[] for i in range(10005)]
dist = [INF]*10005
path = [-1]*10005

def dfs(s):
    for neibor in grp[s]:
        if dist[neibor] > dist[s] + 1:
            dist[neibor] = dist[s] + 1
            path[neibor] = s
            dfs(neibor)

def printPath(s):
    if s == -1:
        return
    
    printPath(path[s])
    print(s )

#_____main_____
FILE_IO()

# this is test case input
grp[1].append(2)
grp[2].append(1)

grp[2].append(4)
grp[4].append(2)

grp[1].append(3)
grp[3].append(1)

grp[3].append(4)
grp[4].append(3)

#ending test case

dist[1] = 0;
dfs(1)

print(f"Sort path is length: {dist[4]}")
printPath(4)


''' output
Sort path is length: 2
1
2
4
'''