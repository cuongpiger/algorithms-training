#https://www.urionlinejudge.com.br/judge/en/problems/view/1624
'''
Comment
'''

class Item:
    def __init__(self, price, weight):
        self.price = price
        self.weight = weight

items = [Item(0, 0) for _ in range (110)]

def knapsack(n, sizeBag):
    dp = [[0 for j in range(sizeBag + 5)] for i in range(n + 5)]
    items[0] = Item(0, 0)

    for i in range(1, n):
        for j in range(sizeBag + 1):
            if items[i].weight > j:
                dp[i][j] = dp[i - 1][j]
            else:
                tmp1 = items[i].price + dp[i - 1][j - items[i].weight]
                tmp2 = dp[i - 1][j]
                dp[i][j] = max(tmp1, tmp2)

    return dp[n - 1][sizeBag]

if __name__ == "__main__":
    while True:
        n = int(input())

        if n == 0:
            break

        for i in range(1, n + 1):
            items[i].price, items[i].weight = map(int, input().split())

        sizeBag = int(input())
        
        print(knapsack(n + 1, sizeBag))