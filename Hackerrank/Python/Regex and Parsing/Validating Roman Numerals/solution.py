"""
Explanation of this regex: https://stackoverflow.com/questions/267399/how-do-you-match-only-valid-roman-numerals-with-a-regular-expression
"""


regex_pattern = r"^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$"

################################################################################
#----------------------------- begin locked code ------------------------------#
import re
print(str(bool(re.match(regex_pattern, input()))))
#------------------------------ end locked code -------------------------------#
################################################################################
