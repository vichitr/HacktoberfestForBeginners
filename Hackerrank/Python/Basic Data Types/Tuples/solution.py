_ = int(input())
input_tuple = tuple(int(x) for x in input().split())
print(hash(input_tuple))
