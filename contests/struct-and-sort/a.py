N, K = map(int, input().split())
x = [int(i) for i in input().split()]

def qsort(arr, low, high):
  if low < high:
      pi = partition(arr, low, high)
      qsort(arr, low, pi - 1)
      qsort(arr, pi + 1, high)

def partition(arr, low, high):
  pivot = arr[high]
  i = low - 1
  for j in range(low, high):
    if arr[j] <= pivot:
      i += 1
      (arr[i], arr[j]) = (arr[j], arr[i])
  i += 1
  (arr[i], arr[high]) = (arr[high], arr[i])
  return i

qsort(x, 0, len(x) - 1)

c = 0

l = 0
r = 1

while (r < N):
  d = x[r] - x[l]

  if (d == K):
    c+=1
    l+=1
    r+=1
  elif (d < K):
    r+=1
  else:
    l+=1

print(c)