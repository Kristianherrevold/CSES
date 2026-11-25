n = int(input())
numbers = list(map(int, input().split()))
greatest = 0
k = 0
for i in range(n-1):
    t = numbers[i]
    greatest = max(greatest,t)
    diff = greatest - numbers[i+1]
    if diff < 0:
        greatest = numbers[i+1]
    if diff > 0:
        k += diff

print(k)