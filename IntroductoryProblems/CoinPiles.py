t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    if a == b == 0:
        print("YES")
    elif a <= 2*b and b <= 2*a and (a+b) % 3 == 0:
        print("YES")
    else:
        print("NO")