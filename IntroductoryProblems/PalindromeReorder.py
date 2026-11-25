import sys
n = sys.stdin.readline().strip()

count = [0]*26
for ch in n:
    count[ord(ch) - 65] += 1
midt = ""
odd = 0
for i in range(26):
    if count[i] % 2 == 1:
        odd += 1
        midt = chr(65+i)

if odd > 1:
    print("NO SOLUTION")
    sys.exit()

venstre = []
for i in range(26):
    venstre.append(chr(65 + i) * (count[i] // 2))

  

left = "".join(venstre)
høyre = left[::-1]
palindrom = left + midt + høyre
print(palindrom)

