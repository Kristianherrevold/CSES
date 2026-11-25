n = int(input())
N = list()


if n <= 3 and n != 1:
    print("NO SOLUTION")
elif n==4:
    print("2 4 1 3")
else:
    if n % 2 == 0:
        N.append(n)
        n = n-1

    i = n
    while i > 2:
        N.append(i-1)
        i -= 2

    i = n
    while i >= 1:
        N.append(i)
        i -= 2

    print(*N)