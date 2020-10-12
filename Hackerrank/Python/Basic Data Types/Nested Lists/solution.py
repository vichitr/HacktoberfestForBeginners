# Read in names and grades to a nested list
n = int(input())
names_grades = [[input(), float(input())] for _ in range(n)]

# Find the second lowest grade
grades_set = {n_g[1] for n_g in names_grades}
second_lowest_grade = sorted(grades_set)[1]

# Find all students with the second lowest grade
second_lowest_students = [n_g[0] for n_g in names_grades
                          if n_g[1] == second_lowest_grade]
print(*sorted(second_lowest_students), sep="\n")
