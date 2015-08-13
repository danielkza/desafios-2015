n = int(input())

count = 0
half = int(n /  2)
for num in range(10**n):
    right = 0
    for _ in range(0, half):
        num, digit = divmod(num, 10)
        right += digit

    left = 0
    for _ in range(0, half):
        num, digit = divmod(num, 10)
        left += digit

    if left == right:
        count += 1

print(count)
