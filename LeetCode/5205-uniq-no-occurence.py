class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        
        uniqList = list(set(arr))
        countList = []
        
        for x in uniqList:
            count = arr.count(x)
            if count not in countList:
                countList.append(count)
                
        uniqCount = list(set(countList))
        
        if (len(uniqList) == len(uniqCount)):
            return True
        else:
            return False
