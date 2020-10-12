from collections import OrderedDict

def merge_the_tools(string, k):
    for i in range(0, len(string), k):
        print(''.join(list(OrderedDict.fromkeys(string[i:i+k]))))

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)
#------------------------------ end locked code -------------------------------#
################################################################################
