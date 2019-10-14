def beginnersTask(list):
    count = 0
    for x in list:
        if x % 2 == 0:
            count = count + 1
    return count

a = beginnersTask([0, 2, 3, 4])
print(a)
