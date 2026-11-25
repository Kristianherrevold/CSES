n = int(input())
sum = n * (n + 1) // 2
if sum % 2 == 0:
    print("YES")
    nums = list(range(1,n+1))
    list_1 = []
    list_2= []

    if n % 4 == 3:
        list_1.append(nums[0])
        list_1.append(nums[1])
        list_2.append(nums[2])
        i = 3
        while len(nums) > i:
            list_1.append(nums[i])
            list_1.append(nums[i+3])
            list_2.append(nums[i+1])
            list_2.append(nums[i+2])
            i+=4
    else: 
        i = 0
        while len(nums) > i:
            list_1.append(nums[i])
            list_1.append(nums[i+3])
            list_2.append(nums[i+1])
            list_2.append(nums[i+2])
            i+=4
    print(len(list_1))
    print(*list_1)
    print(len(list_2))
    print(*list_2)    

else:
    print("NO")