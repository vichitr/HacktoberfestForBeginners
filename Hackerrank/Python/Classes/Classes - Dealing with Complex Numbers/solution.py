################################################################################
#----------------------------- begin locked code ------------------------------#
import math
#------------------------------ end locked code -------------------------------#
################################################################################

class Complex(object):
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
        
    def __add__(self, other):
        real_sum = self.real + other.real
        imaginary_sum = self.imaginary + other.imaginary
        return Complex(real_sum, imaginary_sum)
        
    def __sub__(self, other):
        real_diff = self.real - other.real
        imaginary_diff = self.imaginary - other.imaginary
        return Complex(real_diff, imaginary_diff)
        
    def __mul__(self, other):
        real_prod = (self.real * other.real
            - self.imaginary * other.imaginary)
        imaginary_prod = (self.real * other.imaginary
            + self.imaginary * other.real)
        return Complex(real_prod, imaginary_prod)

    def __truediv__(self, other):
        try:
            conjugate = Complex(other.real, -1 * other.imaginary)
            return (self * conjugate
                * Complex(1.0 / (other.mod().real) ** 2, 0))
        except ZeroDivisionError as err:
            print(err)

    def mod(self):
        return Complex(((self.real ** 2 + self.imaginary ** 2) ** 0.5), 0)

    def __str__(self):
        return "{0:.2f}{1:+.2f}i".format(self.real, self.imaginary)

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n')
#------------------------------ end locked code -------------------------------#
################################################################################