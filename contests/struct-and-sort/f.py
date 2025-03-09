n = int(input())

v = True

pos = (0, 0)

t_t = 0

for i in range(n):
  t, x, y = map(int, input().split())

  qx = abs(x - pos[0])
  qy = abs(y - pos[1])

  s = qx + qy
  d = (t - t_t)

  if d >= s and d%2==s%2:
    pos = (x,y)
    t_t = t
  else:
    v = False
    break

if v:
  print("Yes")
else:
  print("No")