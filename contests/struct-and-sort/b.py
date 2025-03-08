import sys

l = sys.stdin.read().strip().splitlines()

i = 0

t = int(l[0])

r = []

i+=1

for _ in range(t):
  if l[i] == "":
    i+=1

  n = int(l[i])
  i+=1

  c = {}
  for _ in range(n):
    s = l[i]
    if (s in c):
      c[s]+=1
    else:
      c[s]=1
    i+=1

  sa = sorted(c.keys())

  rs = []
  for k in sa:
    rs.append(f"{k} {c[k]}")
  r.append("\n".join(rs))

print("\n".join(r))