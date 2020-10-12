from collections import namedtuple

num_rows = int(input())
column_names = input().split()
Student = namedtuple('Student', column_names)

marks_sum = 0
for _ in range(num_rows):
    fields = input().split()
    student = Student(*fields)
    marks_sum += int(student.MARKS)
print("{:.2f}".format(marks_sum / num_rows))
