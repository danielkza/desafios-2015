from collections import namedtuple

n = int(input())

balances = [((1, 1, 0, 0), 0)]

class Node(object):
    __slots__ = ('key', 'value', 'left', 'right')
    
    def __init__(self, key, value, left, right):
        self.key = key
        self.value = value
        self.left = left
        self.right = right

    def lower_bound_walk(self, key):
        node = self
        lower_bound = None

        parents = list()
        while True:
            done = True
            while node.key > key and node.left:
                done = False
                parents.append((node, True))
                node = node.left
        
            while node.key < key:
                if not lower_bound or node.key > lower_bound.key:
                    lower_bound = node

                if node.right:
                    done = False
                    parents.append((node, False))
                    node = node.right

            if done:
                break

        
        if not lower_bound:
            return

        yield lower_bound

        while parents:
            node, from_right = parents.pop()
            yield node
            for node in (node.left.walk() if from_right else node.right.walk()):
                yield node

    @classmethod
    def insert(cls, root, key, value):
        if not root:
            return Node(key, value, None, None)

        if key < root.key:
            root.left = cls.insert(root.left, key, value)
        elif key > root.key:
            root.right = cls.insert(root.right, key, value)

        return root

    def walk(self):
        if self.left:
            for node in self.left.walk():
                yield node
        yield self
        if self.right:
            for node in self.right.walk():
                yield node


memo = {}

balances = None

for _ in range(n):
    amount, date, time = input().split()
    amount = int(amount)
    day, month = map(int, date.split('.'))
    hour, minute = map(int, time.split(':'))
    date_time = (month, day, hour, minute)

    balances = Node.insert(balances, date_time, amount)
    
    lower_bound = balances.lower_bound_walk(date_time)
    first = next(lower_bound, None)
    if first:
        money, debt = memo[first.key]
        print('memo', money, debt)
    else:
        money, debt = (0, 0)

    money += amount
    if money < 0:
        debt += money
        money = 0

    for node in lower_bound:
        print(node.key)
        t_amount = node.value

        money += t_amount
        if money < 0:
            debt += money
            money = 0

    memo[date_time] = (money, debt)
    
    print(debt)
    # print(min(balance, 0))
