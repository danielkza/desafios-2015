n = int(input())
num = int(input())

digits = list(map(int, str(num)))

def increment(digits, i):
    return list(map(lambda n: (n + i) % 10, digits))

def shift(l):
    return l[1:] + l[:1]

rem = 10 - digits[0]
digits = shift(increment(digits, rem))

for i in range(1, len(digits) - 1):
    rem = 10 - digits[i]
    other_rem = (digits[i + 1] + rem) % 10

    if other_rem < digits[i]:



