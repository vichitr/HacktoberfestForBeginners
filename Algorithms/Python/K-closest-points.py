'''
    This is pure Python implementation of K closest points to origin
'''

'''
    Problem: Given list of points and K, find the closest K points to the origin
    Solution: Sorting list of cdistances, Time Complexity: O(n*log n), Space Complexity: O)n)
'''

def kClosest(points: List[List[int]], K: int) -> List[List[int]]:
    closest = sorted(points, key=lambda p: p[0] * p[0] + p[1] * p[1])
    
    return closest[:K]

def main():
    points = [[1,3],[-2,2]]
    K = 1
    print(kClosest(points, K))