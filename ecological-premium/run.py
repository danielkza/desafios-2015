from collections import namedtuple

Farmer = namedtuple('Farmer', 'size animals eco')

num_cases = int(input())

for _ in range(num_cases):
    num_farmers = int(input())
    farmers = []
    
    for _ in range(num_farmers):
        farmer = Farmer(*map(int, input().split()))
        farmers.append(farmer)

    total = 0
    for farmer in farmers:
        total += ((farmer.size / farmer.animals) * farmer.eco) * farmer.animals

    print(int(total))
