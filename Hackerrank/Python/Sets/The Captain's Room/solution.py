k = int(input())
rooms_list = [int(x) for x in input().split()]

all_rooms = set()
all_repeats = set()
for room in rooms_list:
    if room in all_rooms:
        all_repeats.add(room)
    else:
        all_rooms.add(room)

print(*(all_rooms - all_repeats))
