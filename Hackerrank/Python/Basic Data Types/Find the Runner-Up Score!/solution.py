_ = int(input())
input_list = [int(x) for x in input().split()]

# Remove all occurences of the max score in the list
max_score = max(input_list)
input_list = [score for score in input_list if score != max_score]

# Print the new max (the runner-up)
print(max(input_list))
