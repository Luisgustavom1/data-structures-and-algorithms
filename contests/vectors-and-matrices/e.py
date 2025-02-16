r, c = map(int, input().split())
cc = 0

m = []

ri = [True] * r
ci = [True] * c

for i in range(r):
  aux = []

  e = list(map(int, input().split()))
  for j in e:
    aux.append(j)

  m.append(aux)

for i in range(r):
  for j in range(c):
    if m[i][j] == 1:
      ri[i] = False
      ci[j] = False

for i in range(r):
  for j in range(c):
    if ri[i] == True and ci[j] == True:
      cc+=1

print(cc)