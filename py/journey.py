# https://codeforces.com/problemset/problem/839/C
c = int(input())

if (c == 1):
    print("0.000000")
    exit()

graph = [[] for _ in range(c + 1)]

for i in range(c - 1):
    n, k = map(int, input().split())
    graph[n].append(k)
    graph[k].append(n)

visited = [False] * (c+1)
def dfs(root):
    total = 0
    count = 0

    visited[root] = True

    for node in graph[root]:
        if (not visited[node]):
            count += 1;
            total += dfs(node) + 1

    visited[root] = False

    if (count == 0):
        return 0

    return total / count

res = dfs(1)
print(f"{res:.6f}") 
