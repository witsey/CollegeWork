import sys

import sympy as sp
from sympy import *

input = sys.stdin.readline


x, y = symbols('x y', real=True)
f = x**3 - 5*x*y + y**3
h = 35*x**2 - 350*x + 1000 # since [ y = 10 - x ]

highestProfits = []


def inp():
    return int(input())


t = inp()


def max_profit(inputM):
    boundary = sp.Eq(x + y, m)

    # finding the max inside the boundary first
    hPrime = sp.diff(h, x)
    hPrime_critical_points_eq = sp.Eq(hPrime, 0)
    hPrime_critical_x_points = sp.solve(hPrime_critical_points_eq, x)

    critical_points = []

    y_solution = solve(boundary, y)[0]

    for xPoint in hPrime_critical_x_points:
        yPoint = y_solution.subs(x, xPoint)

        if xPoint > 0:
            if yPoint > 0:
                if xPoint + yPoint <= m:
                    critical_points.append((xPoint, yPoint))

    partial_f_by_x = diff(f, x)
    partial_f_by_y = diff(f, y)

    partial_f_by_x_eq = Eq(partial_f_by_x, 0)
    partial_f_by_y_eq = Eq(partial_f_by_y, 0)

    solutions = solve([partial_f_by_x_eq, partial_f_by_y_eq], (x, y))

    for point in solutions:
        if isinstance(point, int):
            if point[0] > 0:
                if point[1] > 0:
                    if point[0] + point[1] <= m:
                        critical_points.append(point)

    profits = []

    for point in critical_points:
        result = (f.subs({x: point[0], y: point[1]}))
        profits.append(result)

    highestProfit = profits[0]

    for profit in profits:
        if profit > highestProfit:
            highestProfit = profit

    highestProfits.append(highestProfit)


for _ in range(t):
    m = inp()
    max_profit(m)

for profit in highestProfits:
    print(profit)