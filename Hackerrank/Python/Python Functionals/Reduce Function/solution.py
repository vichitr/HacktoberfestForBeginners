################################################################################
#----------------------------- begin locked code ------------------------------#
from fractions import Fraction
from functools import reduce
#------------------------------ end locked code -------------------------------#
################################################################################

def product(fracs):
    t = reduce(lambda frac1, frac2: frac1 * frac2, fracs)
    return t.numerator, t.denominator

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    fracs = []
    for _ in range(int(input())):
        fracs.append(Fraction(*map(int, input().split())))
    result = product(fracs)
    print(*result)
#------------------------------ end locked code -------------------------------#
################################################################################
