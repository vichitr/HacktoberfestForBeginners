from itertools import groupby

string = input()
for char, group in groupby(string):
    print("({}, {})".format(len(list(group)), char), end=" ")
