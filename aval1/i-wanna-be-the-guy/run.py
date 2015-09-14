from sys import stdin

n = int(stdin.readline().rstrip())
x_n, *x_l = map(int, stdin.readline().rstrip().split())
y_n, *y_l = map(int, stdin.readline().rstrip().split())

r = set(x_l) | set(y_l)

if list(range(1, n+1)) == list(r):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
