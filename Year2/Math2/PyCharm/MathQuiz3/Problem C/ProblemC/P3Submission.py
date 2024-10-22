import sys
def inp():
    return int(sys.stdin.readline())

def integral(n):
    if n == 1:
        return -2.0 / 3
    elif n == 0:
        return 1.0
    else:
        return (-2.0 * n / (2 * n + 1)) * integral(n - 1)

n = inp()
result = integral(n)
print(result)
