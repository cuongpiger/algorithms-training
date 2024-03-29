#https://codeforces.com/problemset/problem/892/B
'''
Comment
- The person at the last index of the array is certainly alive because there aren't any person's positions who
is behind him.
- So the answer of this problem is always greater or equal to 1.
- At current position of a person (called is I), he can kill the people who are in front of him (called is J) if J >= I - L[I],
so to solve this problem, we just count the number of position which J < I and J < I - L[I] is the number of people are still alive.
'''

if __name__ == "__main__":
    n = int(input());
    pp = list(map(int, input().split()))
    res = 0;
    behind = int(1e9 + 100)

    for i in range(n - 1, -1, -1):
        # else with the case j >= i - L[i]
        if i < behind:
            res += 1 

        # update behind for next loop
        if behind > i - pp[i]: 
            behind = i - pp[i]

        '''
        if behind is small, we will have many chance to kill as many people as possible, so if 
        behind > i - pp[i] of current person, we will update the variable behind (value behind of current person, called is J), 
        from here to the next time which the variable was updated, the number of people which their index >= behind 
        is the number of people was killed by the person J

        '''

    print(res)