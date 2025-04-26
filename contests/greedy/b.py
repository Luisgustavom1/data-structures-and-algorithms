t = int(input())

for _ in range(t):
  n = int(input())
  s = input()

  if n == 1:
    print("YES")
    continue

  isBin = False
  c = 0
  while not isBin:
    strBin = s
    lc = strBin[0]
    m = {}
    m[lc] = str(c)

    for i in range(n):
      cc = strBin[i]
      if cc not in m:
        m[cc] = "1" if strBin[i-1] == "0" else "0"

      strBin = strBin[:i] + m[cc] + strBin[i + 1:]

    lc = strBin[0]
    for i in range(1, n):
      if strBin[i] == lc:
        break
      
      if i == (n - 1):
        isBin = True

      lc = strBin[i]

    if isBin:
      print("YES")

    if c == 1:
      break

    c += 1

  if not isBin:
    print("NO")
    continue