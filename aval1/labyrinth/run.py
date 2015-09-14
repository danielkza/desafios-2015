n = int(input())
lab = []

for i in range(n):
    lab.append([1 if c == '#' else 0 for c in input()])


def can_move_to(nx, ny):
    if nx >= n or nx < 0:
        return False
    if ny >= n or ny < 0:
        return False
    return lab[ny][nx] == 0

done = set()
todo = [(0, 0), (n-1, n-1)]

walls = 0
while todo:
    x, y = todo.pop()
    if (x,y) in done:
        continue

    done.add((x, y))

    for (dx, dy) in ((0, 1), (0, -1), (1, 0), (-1, 0)):
        nx = x + dx
        ny = y + dy

        if (nx, ny) in done:
            continue
        
        if not can_move_to(nx, ny):
            # left and right edges
            if (nx, ny) not in ((0, -1), (-1, 0), (n-1, n), (n, n-1)):
                walls += 1
        else:
            todo.append((nx, ny))

print(walls * 9)
