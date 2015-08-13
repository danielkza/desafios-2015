from __future__ import print_function

from sys import stdin
from operator import add, mul, sub

n = int(stdin.readline().rstrip())

nums = list(range(1, n + 1))

def ops(a, b):
    yield (a, b, a + b, '+')
    yield (a, b, a * b, '*')
    yield (a, b, a - b, '-')
    yield (b, a, b - a, '-')

run_ops = []
def rec():
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            ej = nums.pop(j)
            ei = nums.pop(i)

            for (a, b, res, op) in ops(ei, ej):
                if len(nums) == 0:
                    if res == 24:
                        run_ops.append("{} {} {} = {}".format(a, op, b, res))
                        return True
                else:
                    nums.append(res)
                    
                    if rec():
                        run_ops.append("{} {} {} = {}".format(a, op, b, res))
                        return True

                    nums.pop()

            nums.insert(i, ei)
            nums.insert(j, ej)

    return False

if rec():
    print("YES")
    for op in reversed(run_ops):
        print(op)
else:
    print("NO")
