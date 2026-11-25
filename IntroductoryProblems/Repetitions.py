sequence = input()
lengste = 1
r = 1
i = 0
while i < len(sequence)-1:
    if sequence[i] == sequence[i+1]:
        r = 1
        while i + 1 < len(sequence) and sequence[i] == sequence[i+1]:
            i+=1
            r+=1
    lengste = max(r,lengste)
    i += 1

print(lengste)