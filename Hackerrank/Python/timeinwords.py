
#by Madhav Prabhu
ByOne=[0,'one','two','three','four','five','six','seven','eight','nine','ten','eleven','twelve',
       'thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','ninteen','twenty']
ByQua=["%s o' clock", "quarter past %s", "half past %s", "quarter to %s"]
for i in range(1,10):
    ByOne.append('twenty %s'%ByOne[i])

h,m=int(input()),int(input())
hour=ByOne[h] if (m<31) else ByOne[h+1]
if not m%15:
    print(ByQua[m//15] % hour)
elif m<30:
    print("%s minute"%ByOne[m]+"s"*(m!=1)+ " past %s"%hour)
else:
    print("%s minute"%ByOne[60-m]+"s"+ " to %s"%hour)