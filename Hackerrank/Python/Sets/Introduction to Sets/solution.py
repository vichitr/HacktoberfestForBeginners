def average(heights):
    heights_set = set(heights)
    return sum(heights_set) / len(heights_set)

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
#------------------------------ end locked code -------------------------------#
################################################################################
