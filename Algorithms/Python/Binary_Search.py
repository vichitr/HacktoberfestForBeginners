def binary_Search(arr,val):
    start=0
    end=len(arr)-1
    while start<=end:
        mid=(start+end)//2 
        if arr[mid]==val:
            return True
        elif arr[mid]>val:
            end=mid-1 
        else:
            start=mid+1 
    return False 
arr=list(map(int,input().split()))
#sort the array if not sorted 
arr.sort()
#val= value to find in array 
val=int(input())
if binary_Search(arr,val):
    print("value found")
else:
    print("value not found")
