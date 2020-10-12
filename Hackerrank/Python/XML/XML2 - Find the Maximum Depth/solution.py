"""
Note that the locked code forces the use of a global variable.
"""

################################################################################
#----------------------------- begin locked code ------------------------------#
import xml.etree.ElementTree as etree
#------------------------------ end locked code -------------------------------#
################################################################################

maxdepth = 0
def depth(elem, level):
    global maxdepth
    if (level == maxdepth):
        maxdepth += 1
    for child in elem:
        depth(child, level + 1)

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    n = int(input())
    xml = ""
    for i in range(n):
        xml =  xml + input() + "\n"
    tree = etree.ElementTree(etree.fromstring(xml))
    depth(tree.getroot(), -1)
    print(maxdepth)
#------------------------------ end locked code -------------------------------#
################################################################################
