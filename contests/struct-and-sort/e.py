
n = int(input())
a = [int(i) for i in input().split()]

c = 0

while True:
  for e in a:
    if (e % 2 != 0):
      print(c)
      exit(0)
      
  c+=1

  for i in range(n):
    a[i] /= 2