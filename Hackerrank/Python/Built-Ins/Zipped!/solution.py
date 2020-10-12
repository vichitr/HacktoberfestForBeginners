N, X = (int(x) for x in input().split())

subject_marks = []
for _ in range(X):
    subject_marks.append([float(x) for x in input().split()])

student_marks = zip(*subject_marks)
average_marks = [(sum(marks) / X) for marks in student_marks]
print(*average_marks, sep='\n')
