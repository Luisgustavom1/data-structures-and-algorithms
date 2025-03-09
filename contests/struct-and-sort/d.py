N, M = map(int, input().split())
arr = list(map(int, input().split()))

indexes = [0] * (N + 1)

for i in range(N):
    indexes[arr[i]] = i

r = []
c = 1

for i in range(1, N):
    if indexes[i + 1] < indexes[i]:
        c += 1

for i in range(M):    
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    x = arr[a]
    y = arr[b]

    affected = set()

    for v in (x - 1, x, y - 1, y):
        if 1 <= v < N: # between 1 and N
            affected.add(v)

    for v in affected:
        if indexes[v + 1] < indexes[v]:
            c -= 1

    arr[a], arr[b] = arr[b], arr[a]
    indexes[x], indexes[y] = indexes[y], indexes[x]
    
    for v in affected:
        if indexes[v + 1] < indexes[v]:
            c += 1

    r.append(c)

print(*r, sep='\n')