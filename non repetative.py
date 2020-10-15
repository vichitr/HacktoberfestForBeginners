n=(input("))
d={}
for x in n:
  d[x]=d.get(x,0)+1
c=0
for k,v in d.items():
  if(v==1):
    c+=1
print(c)
