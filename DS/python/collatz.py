steps = 1
seq_length = 1

for number in range(1, 10):
    start_number = number
    list_length = 1
    #print(number)
    while(number != 1):
        if number % 2 == 0:
            number = number / 2
            list_length += 1
        else:
            number = 3 * number + 1
            list_length += 1

    if list_length > steps:
        steps = list_length
        seq_length = start_number

print("The initial starting number <= 10000000 is", seq_length)
print("The second-longest sequence of integers <= 10000000 is", steps)
