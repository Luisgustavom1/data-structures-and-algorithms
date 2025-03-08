a = int(input())
x = [int(i) for i in input().split()]

c = 1

x.sort()

for i in range(a - 1):
  if (x[i] != x[i+1]):
    c+=1

print(c)