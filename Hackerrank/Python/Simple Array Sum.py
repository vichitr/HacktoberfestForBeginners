#By NAIRITYA TALE
#Algorithms 
#Data Structures 

size=int(input("Entre The Size Of Array"))            #takes input as size of array
ar=[]                                                                   #array declaration
arrsum=0
for i in range(0,size):                                                                                                 
    ar.append(input())                                           #input in the array
    arrsum=arrsum+int(ar[i])                                 #summation of array
print("The Sum Of The Array Is =",arrsum)          #result display 
exit()
