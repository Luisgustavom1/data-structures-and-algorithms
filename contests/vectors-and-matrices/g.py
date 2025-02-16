s = int(input())
arr = list(map(int, input().split()))

v = True

for i in range(s - 1):
  if arr[i] > arr[i + 1]:
    v = False

if v == True:
  print("Yes")
else:
  print("No")