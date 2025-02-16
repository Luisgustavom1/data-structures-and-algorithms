n = int(input())
x = [int(i) for i in input().split()]

c = 0

for i in range(1, n):
    a = x[i]
    b = x[i-1]
    
    if a <= b:
        c += b - a
        x[i] += b - a

print(c)
