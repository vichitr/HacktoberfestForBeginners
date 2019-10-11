"""
This is pure python implementation of interpolation search algorithm
"""

"""Pure implementation of interpolation search algorithm in Python
Be careful collection must be ascending sorted, otherwise result will be
unpredictable
"""
def interpolation_search(sorted_collection, item):

    left = 0
    right = len(sorted_collection) - 1

    while left <= right:

        if sorted_collection[left] == sorted_collection[right]:
            if sorted_collection[left] == item:
                return left
            else:
                return None

        point = left + ((item - sorted_collection[left]) * (right - left)) // (
            sorted_collection[right] - sorted_collection[left]
        )
        if point < 0 or point >= len(sorted_collection):
            return None

        current_item = sorted_collection[point]
        if current_item == item:
            return point
        else:
            if point < left:
                right = left
                left = point
            elif point > right:
                left = right
                right = point
            else:
                if item < current_item:
                    right = point - 1
                else:
                    left = point + 1
    return None
