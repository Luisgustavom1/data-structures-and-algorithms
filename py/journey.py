# https://codeforces.com/problemset/problem/839/C
c = int(input())

graph = [[] for _ in range(c + 1)]
leafs = []

for i in range(c - 1):
    n, k = map(int, input().split())
    graph[n].append(k)

for i in range(c + 1):
    if (len(graph[i]) == 0 and i > 0):
        leafs.append(i)

visited = [False] * (c+1)
distances = [0] * (c + 1)

q = [(1, 0)]
while (len(q) > 0):
    ad = q.pop()
    a = ad[0]
    d = ad[1]
    
    if (a == c):
        continue
    
    nex = graph[a]
    for n in nex:
        if (n not in visited):
            visited[n] = True
            q.append((n, d+1))
            distances[n] = d+1

s = 0
for p in leafs:
    s = s + distances[p]

print(f"{(s / len(leafs)):.6f}") 
