s, r = map(int, input().split())
arr = list(map(int, input().split()))
arr_ = [None] * s

r %= s

for i in range(s):
  n = (i + r) % s
  arr_[i] = arr[n]

print(*arr_)