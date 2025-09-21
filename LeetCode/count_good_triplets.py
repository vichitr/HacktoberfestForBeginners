# Link - https://leetcode.com/problems/count-good-triplets/submissions/

class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        
        perm = combinations(arr, 3)
        answer = []
        # c = 0
        for i in perm:
            if abs(i[0] - i[1]) <= a and abs(i[1] - i[2]) <= b and abs(i[0] - i[2]) <= c:
                answer.append(i)
                # c += 1
                    
        return len(answer)
        # return c
