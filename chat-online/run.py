from sys import stdin
from itertools import chain

p, q, l, r = map(int, stdin.readline().rstrip().split())

x_times = set()
z_times = []

for i in range(p):
    s, e = map(int, stdin.readline().rstrip().split())
    x_times |= set(range(s, e+1))
    
for i in range(q):
    s, e = map(int, stdin.readline().rstrip().split())
    z_times.append((s, e+1))
    
count = 0
for t in range(l, r+1):
    z_t_times = set(chain.from_iterable(range(t + s, t + e) for (s,e) in z_times))
    if x_times & z_t_times:
        count += 1

print(count)
   
