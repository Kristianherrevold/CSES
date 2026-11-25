import math
n = int(input())

for k in range(1,n+1):
    if k == 1:
        print(0)
    elif k == 2:
        print(6)

    elif k == 3:
        print(28)

    else:
        r = k*k
        mulige = r*(r-1) // 2
        ugunstige = 4*r - 12*k + 8
        print(mulige - ugunstige)

