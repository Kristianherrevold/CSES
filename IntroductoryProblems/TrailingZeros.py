import math
n = int(input())
N_l = math.factorial(n)
z = 0
t = 10
for i in range(1, (int(N_l.bit_length() / math.log2(10)) + 1) + 1):
    if N_l % t == 0:
        z +=1
        t *= 10
    else:
        break

print(z)
