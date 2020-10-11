#Author: Rakshit Naidu

if __name__ == '__main__':
    n = int(input().strip())

    if n % 2 ==0 and n > 20:
        print("Not Weird")
    elif n % 2 ==0 and n > 5 and n < 21:
        print("Weird")
    elif n % 2==0 and n > 1 and n < 6:
        print("Not Weird")
    elif n % 2 == 1:
        print("Weird")
        
        
 # created by Rupali

if __name__ == '__main__':
    n = int(input().strip())

    if n%2==0 :
        if n%2==0 & n>20 |  2<=n<=5 :
           print("Not Weird")    

        elif 6<=n<=20  :
         print("Weird")

        else:
            print("Not Weird") 

       

   
    else :
      print("Weird")  
