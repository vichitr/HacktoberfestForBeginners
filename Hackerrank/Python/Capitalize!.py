def solve(s):
    a = []
    l = re.split(" ", s)
    for c in l:
        a.append(c.capitalize())
    return " ".join(a)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()