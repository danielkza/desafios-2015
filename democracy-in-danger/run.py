n = int(input())
groups = map(int, input().split())
groups = sorted(groups)
groups = groups[:int((len(groups) / 2.0) + 1)]

r = sum(map((lambda n: int((n / 2.0) + 1)), groups))
print(r)
