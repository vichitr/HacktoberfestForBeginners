n = int(input())
student_marks = {}
for _ in range(n):
    name, *line = input().split()
    scores = [float(s) for s in line]
    student_marks[name] = scores

query_name = input()
query_scores = student_marks[query_name]
average_score = sum(query_scores) / len(query_scores)
print("{0:.2f}".format(average_score))
