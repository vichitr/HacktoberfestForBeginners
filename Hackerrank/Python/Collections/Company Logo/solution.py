from collections import Counter

name = input()
letter_freq = Counter(name)
most_common = list(letter_freq.items())
most_common.sort(key=lambda tup: (-tup[1], tup[0]))

for letter, freq in most_common[:3]:
    print(letter, freq)
