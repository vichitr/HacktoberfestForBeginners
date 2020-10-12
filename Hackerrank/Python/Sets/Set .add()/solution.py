num_stamps = int(input())

countries = set()
for _ in range(num_stamps):
    countries.add(input())

print(len(countries))
