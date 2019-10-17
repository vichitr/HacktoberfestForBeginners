# author name: namanbansal013

def multiply(A, B, m, n): 
  
    prod = [0] * (m + n - 1); 
      
    # Multiply two polynomials term by term 
      
    # Take ever term of first polynomial 
    for i in range(m): 
          
        # Multiply the current term of first  
        # polynomial with every term of  
        # second polynomial. 
        for j in range(n): 
            prod[i + j] += A[i] * B[j]; 
  
    return prod; 


s1=[int(i) for i in input().split()]
n,k=s1[0],s1[1]
s2=[int(j) for j in input().split()]
s3=[]
s3=list(set(s2))
s4=[]
if(k==0):
    print(1)
elif(k==1):
    print(n+1)
elif(k>=2):
    for c in range(0,len(s3)):
        s4.append(s2.count(s3[c]))
    p=[s4[0],1]
    for d in range(1,len(s4)):
        e=[s4[d],1]
        p=multiply(p, e, len(p), 2)
    if len(s4)>k:
        print((sum(p[len(s3)-k:]))%1000000007)  
    else:
        print(sum(p)%1000000007)
