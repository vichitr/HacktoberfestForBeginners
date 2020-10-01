class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxa=0
        lptr=0
        rptr=len(height)-1
        
        while(lptr<rptr):
            area=min(height[lptr],height[rptr])*(rptr-lptr)
            maxa=max(maxa,area)
            if height[lptr] < height[rptr]:
                lptr=lptr+1
            else:
                rptr=rptr-1
        return maxa