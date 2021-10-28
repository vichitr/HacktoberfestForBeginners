# cook your dish here
for _ in range(int(input())):
    n,x=map(int,input().split())
    l=list(map(int,input().split()))
    d={}
    maxs=1
    d1={}
    d2 = {}
    u=0
    for i in range(n):
        try:
            d[l[i]]+=1 
            '''if(d[l[i]]>=maxs):
                maxs=d[l[i]]
                u=l[i]'''
        except:
            d[l[i]]=1 
        try:
            d1[l[i]]+=1 
        except:
            d1[l[i]]=1
        if(l[i]!=l[i]^x):
            try:
                d[l[i]^x]+=1 
                '''if(d[l[i]^x]>=maxs):
                    maxs=d[l[i]^x]
                    u=l[i]^x'''
            except:
                d[l[i]^x]=1
    maxs = d[max(d, key= lambda x: d[x])]
    maxs1=0
    l1=[]
    for j in d.keys():
        if(d[j]==maxs):
            l1.append(j)
    try:
        maxs1 = d1[l1[0]]
        for j in l1:
            try:
                if(d1[j]>maxs1):
                    maxs1=d1[j]
            except:
                continue
    except:
        pass
    print(maxs,maxs-maxs1)
    '''try:
        print(maxs,maxs-max(d1[u],d1[u^x]))
    except:
        print(maxs,0)'''
