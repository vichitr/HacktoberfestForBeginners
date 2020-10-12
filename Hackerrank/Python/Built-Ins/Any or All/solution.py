def is_palandromic(num):
    temp = num
    reverse = 0
    while temp != 0:
        reverse = (reverse * 10) + (temp % 10)
        temp //= 10
    return num == reverse

_ = input()
nums = [int(x) for x in input().split()]

print(all(num > 0 for num in nums)
    and any(is_palandromic(num) for num in nums))
