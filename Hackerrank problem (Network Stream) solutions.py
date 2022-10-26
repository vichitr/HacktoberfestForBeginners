def largeRepackagedPacket(arr):
    twoP=[int(2**i) for i in range(31)]
    x=0
    ans=0
    for i in arr:
        i=i+x 
        for j in range(31):
            if i<twoP[j]:
                break
        x=i-twoP[j-1]
        if ans<=twoP[j-1]:
            ans=twoP[j-1]
    return ans


Packets=[]
for i in range(int(input())):
    Packets.append(int(input()))
print(largeRepackagedPacket(Packets))
