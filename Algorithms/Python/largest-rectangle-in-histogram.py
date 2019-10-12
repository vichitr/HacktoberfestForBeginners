'''
This is python implementation of largest rectangle in histogram problem
'''

'''
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
'''

def largestRectangleArea(lst: List[int]) -> int:
    if len(lst)==0:
        return 0
    i = 0
    top = 0
    area = -1
    maxArea = -1
    st = []
    while i<len(lst):
        if len(st)==0 or lst[st[-1]] <= lst[i]:
            st.append(i)
            i+=1
        else:
            top = st.pop()
            if len(st)!=0:
                area = lst[top]*(i - 1 - st[-1])
            else:
                area = lst[top]*(i-1+1)
            maxArea = max(area,maxArea)

    while len(st)!=0:
        top = st.pop()
        if len(st)!=0:
            area = lst[top]*(i - 1 - st[-1])
        else:
            area = lst[top]*i
        maxArea = max(area,maxArea)

    return maxArea