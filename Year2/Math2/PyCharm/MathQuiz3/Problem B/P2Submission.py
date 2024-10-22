import sys
input = sys.stdin.readline

profits = []


def inp():
    return int(input())


def profit_function(x, y):
    return x**3 - 5*x*y + y**3


t = inp()

for _ in range(t):
    m = inp()
    highestProfit = profit_function(1, m - 1)
    profits.append(highestProfit)

for profit in profits:
    print(profit)

