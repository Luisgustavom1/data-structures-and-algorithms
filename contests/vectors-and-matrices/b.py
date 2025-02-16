n = int(input())
x = [int(i) for i in input().split()]

m = {}

for i in range(n):
    m[i+1] = True

for i in range(n - 1):
  a = x[i]
  del m[a]

for k in m.keys():
  print(k)
