t = int(input())
for _ in range(t):
    N = list(input().split())
    y,x= int(N[0]),int(N[1])
    m = max(x,y)
    if m % 2 == 1:
        if x == m:
            sum = x**2 - y + 1
        elif y == m:
            sum = m**2 -2*m + x + 1
    if m % 2 == 0:
        if y == m:
            sum = m*m - x + 1
        elif x == m:
            sum = m**2 - 2*m + y + 1
    print(sum)