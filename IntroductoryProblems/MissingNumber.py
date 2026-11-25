n = int(input())
Nl = list(map(int, input().split()))

all_nums = set(range(1, n+1))
given_nums = set(Nl)

missing = all_nums - given_nums
print(missing.pop())