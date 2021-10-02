M = 13
P = 8

for home in range (M):
    missed = [-1]*M
    print("---- home:",home,"----")
    hp = 1 + home % P
    for i in range (M):
        hit = (home + i * hp)%M
        print(hit, end=",")
        missed[hit] = 1
    
    print("    missed:",end="")
    
    for k in range(M):
        if missed[k] == -1:
            print(k,end=",")
    print("")
