#This code is contributed by Shreevatsa N, @vatsa287

#Given the participants score sheet for your University Sports Day,
#you are required to find the runner-up score.
#You are given scores. Store them in a list and find the score of the runner-up. 

if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    
    listnew=[] 
    for i in arr:
        if i not in listnew:
            listnew.append(i)
    listnew.sort(reverse=True) #listnew.sort() print(listnew[-1])
    print(listnew[1])


