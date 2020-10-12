from math import log

def print_formatted(num):
    for i in range(1, num + 1):
        width = int(log(n, 2) + 1) # Get width of binary represenation.
        print("{n:{w}d} {n:{w}o} {n:{w}X} {n:{w}b}".format(n=i, w=width))

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
#------------------------------ end locked code -------------------------------#
################################################################################
