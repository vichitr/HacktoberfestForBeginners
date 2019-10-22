def merge(left, right):
    li, ri = 0, 0
    retval = []
    while li < len(left) and ri < len(right):
        if left[li] < right[ri]:
            retval.append(left[li])
            li += 1
        else:
            retval.append(right[ri])
            ri += 1

    retval += left[li:]
    retval += right[ri:]
    return retval


def merge_sort(array):
    # base case
    if len(array) <= 1:  
        return array

    # divide array in half and do recursion
    half = len(array) // 2
    left = merge_sort(array[:half])
    right = merge_sort(array[half:])

    return merge(left, right)


def sort():
    list = [5, 7, 6, 2, 1, 7, 3]
    sorted_list = merge_sort(list)
    print 'Array after sorting: ', sorted_list

if __name__ == '__main__':
    sort()