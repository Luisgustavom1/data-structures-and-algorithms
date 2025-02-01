from queue import PriorityQueue

def prim(graph: list, size: int):
  c = 0
  Q = PriorityQueue(size)
  K = [float('inf')] * size
  visited = [False] * size

  for n, w in graph[0]:
    Q.put((w, n))
    
  visited[0] = True
  K[0] = 0

  while Q.empty() == False:
    weight, u = Q.get()
    if not visited[u]:
      visited[u] = True
      c += weight
      for v, w in graph[u]:
        if not visited[v] and w < K[v]:
          K[v] = w
          Q.put((w, v))

  return c

def main():
    while True:
        M, N = map(int, input().strip().split())
        if M == 0 and N == 0:
            break

        graph = [[] for _ in range(M)] 
        for _ in range(N):
            v, u, w = map(int, input().strip().split())
            
            graph[v].append((u, w))
            graph[u].append((v, w))

        print(prim(graph, M))

if __name__ == "__main__":
  main()
